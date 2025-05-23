#include <string>
#include <vector>

// 相当于求 s 和 t 的最大公共子序列，然后判断最大公共子序列和s的长度是否相等

// dp[i][j]  i - 1 和 j - 1 的最大公共子序列的长度

bool isSubsequence(std::string s, std::string t)
{
    std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(t.size() + 1, 0));

    int result = 0;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }

            if (dp[i][j] > result)
            {
                result = dp[i][j];
            }
        }
    }

    return result == s.size() ? true : false;
}

bool isSubsequencev2(std::string s, std::string t)
{
    if (s.size() < 1)
        return true;

    int index = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == s[index])
        {
            index++;

            if (index == s.size())
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    std::string s = "abc";
    std::string t = "ahbgdc";

    isSubsequence(s, t);
}