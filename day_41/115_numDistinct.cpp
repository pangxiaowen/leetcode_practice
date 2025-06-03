#include <cstddef>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

// 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

// 字符串的一个 子序列
// 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是
// "ABCDE" 的一个子序列，而 "AEC" 不是）

// 1.
// dp[i][j]  表示 s 的前 i 个字符中，t 的前 j 个字符的子序列个数

// 2.DP 转移方程
// if (s[i - 1] == t[j - 1])
//    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
// else
//    dp[i][j] = dp[i - 1][j];

// 3.初始化
// dp[i][0] = 1, 表示空字符串 t 在 s 的前 i 个字符中出现的次数为 1
// dp[0][j] = 0, 表示非空字符串 t 在空字符串 s 中出现的次数为 0
// dp[0][0] = 1, 表示空字符串 t 在空字符串 s 中出现的次数为 1

int numDistinct(std::string s, std::string t)
{

    std::vector<std::vector<std::uint64_t>> dp(s.size() + 1,
                                               std::vector<std::uint64_t>(t.size() + 1, 0));

    for (int i = 0; i <= s.size(); i++)
        dp[i][0] = 1;

    for (int j = 1; j <= t.size(); j++)
        dp[0][j] = 0;

    dp[0][0] = 1; // 空字符串 t 在空字符串 s 中出现的次数为 1

    for (int i = 1; i < s.size() + 1; i++)
    {
        for (int j = 1; j < t.size() + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                // 如果s[i-1] == t[j-1]
                // 那么可以选择将s[i-1]加入到子序列中，或者不加入
                // 如果加入，则需要考虑s的前i-1个字符和t的前j-1个字符
                // 如果不加入，则只需要考虑s的前i-1个字符和t的前j个字符
                // 我们考虑的是j是i的子序列个数，因此j必须是完整的
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[s.size()][t.size()];
}

int count = 0;
void backTrack(std::string &s, std::string &t, std::string result, int start)
{
    if (result == t)
    {
        count++;
        return;
    }
    for (int i = start; i < s.size(); i++)
    {
        result.push_back(s[i]);
        backTrack(s, t, result, i + 1);
        result.pop_back();
    }
}
int numDistinctv2(std::string s, std::string t)
{

    std::string result;
    backTrack(s, t, result, 0);
    return count;
}