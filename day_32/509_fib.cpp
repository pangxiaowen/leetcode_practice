#include <vector>

int fib(int n)
{
    if (n < 2)
        return n;

    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 下标的含义
// dp[i] 第i项数组的和

// DP公式
// dp[i] = dp[i-1] + dp[n-2]

// 初始化
// dp[0] = 0
// dp[1] = 1

// 遍历顺序
// 由于n是从 n-1 和 n-2推理得出，所以从小到大

// dp[2] = dp[1] + dp[0] = 1
// dp[3] = dp[2] + dp[1] = 2
