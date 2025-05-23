#include <string>
#include <vector>

// 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

// 你可以对一个单词进行如下三种操作：

//     插入一个字符

//     删除一个字符

//     替换一个字符

// dp[i][j] i-1 和 j-1，最少操作多少次时的 i-1 == j-1

// if(word1[i-1] == word2[j-1])
//      dp[i][j] = dp[i-1][j-1];
// else
//      增删改

int minDistance(std::string word1, std::string word2)
{
    std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));

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
                dp[i][j] =
                    std::min(dp[i - 1][j - 1] + 1, std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        }
    }

    return dp[word1.size()][word2.size()];
}