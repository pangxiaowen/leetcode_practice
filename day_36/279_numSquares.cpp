#include <cmath>
#include <cstdint>
#include <math.h>
#include <vector>

// 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于
// n。你需要让组成和的完全平方数的个数最少。
// 给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

// 从一组完全平方数中选取若干个数，使得它们的和等于 n，且个数最少。

// 下标含义
// dp[j] 组成和为 j 的完全平方数的最少数量。

// DP 公式
// values[i] 表示第 i 个完全平方数，
// dp[j] = min(dp[j], dp[j - values[i]] + 1)

// 初始化
// dp[0] = 0，表示和为 0 不需要任何完全平方数。

// 遍历顺序
// 本题是求个数，不用考虑排序
// 因此 先遍历完全平方数字，再遍历n

int numSquares(int n)
{
    // 确认dp数组的下标
    // dp[j], 和为j的完全平方数的最少数量
    std::vector<int> dp(n + 1, INT32_MAX);

    // 计算从1～std::sqrt(n) 所有的完全平方数
    std::vector<int> values;
    for (int i = 0; i <= std::sqrt(n); i++)
    {
        values.push_back(i * i);
    }

    // 初始化
    dp[0] = 0;

    for (int i = 0; i < values.size(); i++)
    {
        for (int j = values[i]; j < n + 1; j++)
        {
            if (dp[j - values[i]] != INT32_MAX)
                dp[j] = std::min(dp[j], dp[j - values[i]] + 1);
        }
    }

    return dp[n] == INT32_MAX ? -1 : dp[n];
}

int numSquaresv2(int n)
{
    // 确认dp数组的下标
    // dp[j], 和为j的完全平方数的最少数量
    std::vector<int> dp(n + 1, INT32_MAX);

    // 初始化
    dp[0] = 0;

    for (int i = 0; i * i <= n; i++)
    {
        for (int j = i * i; j < n + 1; j++)
        {
            if (dp[j - i * i] != INT32_MAX)
                dp[j] = std::min(dp[j], dp[j - i * i] + 1);
        }
    }

    return dp[n] == INT32_MAX ? -1 : dp[n];
}

int numSquaresv3(int n)
{
    // 确认dp数组的下标
    // dp[j], 和为j的完全平方数的最少数量
    std::vector<int> values;
    for (int i = 1; i * i <= n; i++)
    {
        values.push_back(i * i);
    }

    std::vector<std::vector<int>> dp(values.size(), std::vector<int>(n + 1, INT32_MAX));

    for (int i = 0; i < values.size(); i++)
    {
        dp[i][0] = 0; // 和为0不需要任何完全平方数
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (i % values[0] == 0)
        {
            dp[0][i] = i / values[0]; // 使用多少个values[0]凑成i
        }
    }

    for (int i = 0; i < values.size(); i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (j >= values[i])
            {
                dp[i][j] = std::min(dp[i - 1][j],
                                    dp[i][j - values[i]] == INT32_MAX ? INT32_MAX
                                                                      : dp[i][j - values[i]] + 1);
            }
            else
            {
                dp[i][j] = dp[i - 1][j]; // 不使用当前完全平方数
            }
        }
    }

    return dp[values.size() - 1][n] == INT32_MAX ? -1 : dp[values.size() - 1][n];
}

int main() { numSquares(4); }