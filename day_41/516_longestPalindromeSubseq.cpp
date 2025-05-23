#include <cstddef>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

// 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
// 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
// dp[i][j]

// s 和 rs 的最长公共子序列
// dp[i][j] i-1 和 j-1 的最长公共子序列长度

// if(s[i-1] == rs[j-1])
//      dp[i][j] = dp[i-1][j-1] + 1;
// else
//      dp[i][j] = std::max(dp[i-1][j], dp[i][j-1])

int longestPalindromeSubseq(std::string s)
{
    std::string rs(s.rbegin(), s.rend());
    std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(rs.size() + 1, 0));

    for (int i = 1; i < s.size() + 1; i++)
    {
        for (int j = 1; j < rs.size() + 1; j++)
        {
            if (s[i - 1] == rs[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[s.size()][rs.size()];
}

int longestPalindromeSubseqv2(std::string s)
{
    // dp[i][j] [i][j]区间内最大回文串长度
    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));

    for (int i = 0; i < s.size(); i++)
    {
        dp[i][i] = 1;
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    return dp[s.size()][s.size()];
}

int main()
{
    std::string s = "bbbab";

    std::cout << longestPalindromeSubseq(s) << std::endl;
}