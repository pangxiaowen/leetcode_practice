#include <vector>

// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 持有两只股票
int maxProfit(std::vector<int> &prices)
{
    // 确认下标的含义
    // dp[i][0] 什么都不做的最大利润
    // dp[i][1] 第一次交易 持有股票的最大利润
    // dp[i][2] 第一次交易 不持有股票的最大利润
    // dp[i][3] 第二次交易 持有股票的最大利润
    // dp[i][4] 第二次交易 不持有股票的最大利润

    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(5, 0));

    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }

    return std::max(dp[prices.size() - 1][2], dp[prices.size() - 1][4]);
}
