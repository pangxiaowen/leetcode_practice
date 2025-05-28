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

// 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。
// 返回你可以获得的最大乘积。

// 下标的含义
// dp[n] , 正整数n可以获得的最大乘积

// DP公式，
// dp[n] = std::max(dp[n], (n - i) * i)  将正整数n拆成两个正整数的和
// dp[n] = std::max(dp[n], (n - i) * dp[i]) 将正整数n拆成多个正整数的和
// dp[n] = std::max(dp[n], (n-i)*i, (n-i)*dp[i])

// 初始化
// dp[0] = 0
// dp[1] = 1

// 遍历顺序
// n 是 由 0～n范围内的i推导出的，所以从小到大

int integerBreak_(int n)
{
    std::vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i < n + 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i] = std::max(dp[i], std::max((i - j) * j, (i - j) * dp[j]));
        }
    }

    return dp[n];
}