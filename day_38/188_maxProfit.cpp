#include <vector>

// 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 持有两只股票
int maxProfit(int k, std::vector<int> &prices)
{
    // 确认下标的含义
    // dp[i][0] 什么都不做的最大利润
    // dp[i][1] 第一次交易 持有股票的最大利润
    // dp[i][2] 第一次交易 不持有股票的最大利润
    // dp[i][3] 第二次交易 持有股票的最大利润
    // dp[i][4] 第二次交易 不持有股票的最大利润

    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2 * k + 1, 0));

    // 第一天的情况
    for (int i = 0; i < 2 * k + 1; i++)
    {
        if (i % 2 == 1)
        {
            dp[0][i] = -prices[0];
        }
    }

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j < 2 * k + 1; j++)
        {
            if (j % 2 == 1)
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            }
        }
    }

    int max = 0;

    for (auto it : dp[prices.size() - 1])
    {
        max = std::max(max, it);
    }

    return max;
}
