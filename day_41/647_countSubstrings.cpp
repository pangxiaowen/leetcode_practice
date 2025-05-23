#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// acacac

// a c a c a c
// aca acaca
// cacac

// cacaca

// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
// 回文字符串 是正着读和倒过来读一样的字符串。
// 子字符串 是字符串中的由连续字符组成的一个序列。

// dp[i][j] [i, j] 之间是否为回文子串

int countSubstrings(std::string s)
{
    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), false));

    int result = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1) // i 与 j 下标相同 或者， i和j是相连的元素
                {
                    result++;
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1]) // 如果 [i+1, j-1] 这个区间内是回文的
                {
                    result++;
                    dp[i][j] = true;
                }
            }
        }
    }

    return result;
}

int main()
{
    std::string s = "aaa";
    std::cout << countSubstrings(s) << std::endl;
}