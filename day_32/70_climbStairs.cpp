#include <vector>

int climbStairs(int n)
{
    if (n <= 1)
        return n;
    std::vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// 下标的含义
// dp[i] 爬到第i层有多少种方法

// DP 公式
// dp[i] = dp[i-1] + dp[i-2]

// 初始化
// dp[1] = 1
// dp[2] = 2

// 遍历顺序
// 由于i由 i-1 和 i-2 推出来， 所以从小到大

// dp[3] = dp[2] + dp[1] = 3
