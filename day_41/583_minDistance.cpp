#include <cstdint>
#include <string>
#include <type_traits>
#include <vector>

// 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
// 每步 可以删除任意一个字符串中的一个字符。

// 下标含义
// dp[i][j] i-1 和 j -1 个 元素，至少进行多少次删除能够相等。

// DP公式
// if(word1[i-1] == word2[j-1])
//     dp[i][j] = dp[i-1][j-1]
// else
//     dp[i][j] = std::min(dp[i-1][j], dp[i][j-1])

// 初始化
// dp[0][0] = 0
// dp[i][0] = 0~i
// dp[0][j] = 0~j

int minDistance(std::string word1, std::string word2)
{
    std::vector<std::vector<int>> dp(word1.size() + 1,
                                     std::vector<int>(word2.size() + 1, INT32_MAX));

    dp[0][0] = 0;

    for (int i = 1; i < word1.size() + 1; i++)
    {
        dp[i][0] = i;
    }

    for (int j = 1; j < word2.size() + 1; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i < word1.size() + 1; i++)
    {
        for (int j = 1; j < word2.size() + 1; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[word1.size()][word2.size()];
}

int minDistancev2(std::string word1, std::string word2)
{
    std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));

    for (int i = 1; i < word1.size() + 1; i++)
    {
        for (int j = 1; j < word2.size() + 1; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 最小删除次数 = word1.size() + word2.size() - 2 * LCS
    int lcs = dp[word1.size()][word2.size()];

    return word1.size() + word2.size() - 2 * lcs;
}