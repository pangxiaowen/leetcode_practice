#include <cmath>
#include <cstdint>
#include <math.h>
#include <vector>

// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
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

int main() { numSquares(4); }