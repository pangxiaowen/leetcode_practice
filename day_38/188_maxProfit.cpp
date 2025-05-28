#include <vector>

// 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 这里的 k 笔交易指的是最多可以进行 k 次买入和卖出操作
// 状态转移方程比较复杂，主要是因为需要考虑多次交易的情况
// 以及在每次交易中持有或不持有股票的状态。
// dp[i][j] 表示在第 i 天，状态为 j 时的最大利润
// 状态 j 的含义如下：
// j = 0: 什么都不做
// j = 1: 第一次交易，持有股票
// j = 2: 第一次交易，不持有股票
// .....
// j = 2 * k - 1: 第 k 次交易，持有股票
// j = 2 * k: 第 k 次交易，不持有股票

// DP公式
// dp[i][0] = dp[i - 1][0] // 什么都不做

// dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]) 当 j 为奇数时，表示在第 i
// 天买入股票后，手中的金额为 dp[i-1][j-1] - prices[i]

// dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]) 当 j 为偶数时，表示在第 i
// 天卖出股票后，手中的金额为 dp[i-1][j-1] + prices[i]

// 初始化
// 只针对持有股票的状态进行初始化
// dp[0][x] = -prices[0] 当 x 为奇数时，表示在第 0 天买入股票后，手中的金额为 -prices[0]
// dp[0][0] = 0 表示在第 0 天什么都不做，手中的金额为 0

// 同一时间只能持有一只股票
int maxProfit(int k, std::vector<int> &prices)
{
    // 确认下标的含义

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

    return dp[prices.size() - 1][2 * k]; // 返回最后一天不持有股票的最大利润
}

int maxProfitv2(int k, std::vector<int> &prices)
{
    // 确认下标的含义
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2 * k + 1, 0));

    // 初始化
    for (int i = 1; i < 2 * k + 1; i++)
    {
        if (i % 2 == 1)
        {
            dp[0][i] = -prices[0];
        }
    }

    for (int i = 1; i < prices.size(); i++)
    {
        for (int j = 1; j < 2 * k + 1; j++)
        {
            if (j % 2 == 0) // j为偶数的时候，记录的是不持有股票的状态
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            }
            else // j为奇数的时候，记录的是持有股票的状态
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            }
        }
    }

    return dp[prices.size() - 1][2 * k]; // 返回最后一天不持有股票的最大利润
}