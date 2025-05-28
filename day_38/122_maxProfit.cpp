#include <vector>

// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
// 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股
// 股票。你也可以先购买，然后在 同一天 出售。
// 返回 你能获得的 最大 利润 。

// 可以购买多次彩票, 但是只能持有一只

int maxProfit(std::vector<int> &prices)
{
    // 确认下标的含义
    // dp[i][0] 第i天， 持有股票的最大利润
    // dp[i][1] 第i天， 不持有股票的最大利润

    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));

    dp[0][0] = -prices[0]; // 第一天买入股票后， 手中的金额为-prices[0]
    dp[0][1] = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        // 第i天持有股票的最大利润 =
        // std::max(第i-1天持有股票的最大利润，第i-1天不持有股票的最大利润 - 第i天的股票价格)
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);

        // 第i天不持有股票的最大利润 =
        // std::max(第i-1天不持有股票的最大利润， 第i-1天持有股票的最大利润 + 第i天的股票价格)
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return dp[prices.size() - 1][1];
}

int maxProfitv2(std::vector<int> &prices)
{
    // 确认下标的含义
    // dp[i][0] 第i天， 持有股票时的最大利润
    // dp[i][1] 第i天， 不持有股票的最大利润
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));

    dp[0][0] = -prices[0]; // 第一天持有股票时的最大利润为-prices[0]
    dp[0][1] = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        // 第i天持有股票的最大利润, 从两个状态转移而来
        // 1. 第i-1天持有股票的最大利润
        // 2. 第i-1天不持有股票的最大利润 - 第i天的股票价格

        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[1]);

        // 第i天不持有股票的最大利润, 从两个状态转移而来
        // 1. 第i-1天不持有股票的最大利润
        // 2. 第i-1天持有股票的最大利润 + 第i天的股票价格
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    // 返回最后一天不持有股票的最大利润
    // 因为最后一天不持有股票的最大利润就是我们能获得的最大利润
    // 如果最后一天持有股票，那么就没有卖出，无法获得利润
    return dp[prices.size() - 1][1];
}