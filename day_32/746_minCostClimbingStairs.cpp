#include <vector>

// 下标含义
// dp[i] 爬到第i层的最小花费

// dp公式
// dp[i] = std::min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])

// 初始化
// dp[0] = 0
// dp[1] = 0

// 顺序
// i 由 i-1 和 i-2 推导出来， 所以从小到大

int minCostClimbingStairs(std::vector<int> &cost)
{
    std::vector<int> dp(cost.size() + 1, 0);

    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= cost.size(); i++)
    {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[cost.size()];
}