#include <vector>

int integerBreak(int n)
{
    // 确认dp数组，以及下标的含义， dp[i]拆分数字i的最大乘积
    std::vector<int> dp(n + 1, 0);

    // 确认dp公式
    // dp[i] = std::max(dp[i], std::max((i-j)*j, dp[i-j]*j))

    // 初始化
    // dp[0], dp[1] 是没有意义的
    dp[2] = 1; // 1 * 1

    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = std::max(dp[i], std::max((i - j) * j, dp[i - j] * j));
        }
    }

    return dp[n];
}