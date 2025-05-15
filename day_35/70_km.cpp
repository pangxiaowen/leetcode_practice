#include <cstdint>
#include <vector>

int run(int n, std::vector<int> &weight)
{
    // dp下标的含义
    // dp[j]， 到j阶有多少种不同的方式

    std::vector<int> dp(n + 1, 0);

    // dp公式
    // dp[j] += dp[j - w[i]]

    // 初始化
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < weight.size(); j++)
        {
            if (i >= weight[i])
                dp[i] += dp[i - weight[i]];
        }
    }

    return dp[n];
}