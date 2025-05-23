#include <string>
#include <vector>

// dp[i][j], i-1 和 j-1 长度下的最长公共子序列

// if(s1[i-1] == s2[j-1])
//      dp[i][j] = dp[i-1][j-1] + 1
// else
//      dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);

//      a  c  e
//   a  1  1  1
//   b  1  1  1
//   c  1  2  1
//   d  1  2  1
//   e  1  2  3

//      b  l
//   y  0  0
//   b  1  1
//   y  1  1

int longestCommonSubsequence(std::string text1, std::string text2)
{
    std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if (text1.at(i - 1) == text2.at(j - 1))
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[text1.size()][text2.size()];
}