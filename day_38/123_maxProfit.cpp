#include <vector>

// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 本题的状态转移方程比较复杂，主要是因为需要考虑两次交易的情况
// 以及在每次交易中持有或不持有股票的状态。

// 这里的状态转移方程是基于动态规划的思想来实现的
// dp[i][j] 表示在第 i 天，状态为 j 时的最大利润
// 状态 j 的含义如下：
// j = 0: 什么都不做
// j = 1: 第一次交易，持有股票
// j = 2: 第一次交易，不持有股票
// j = 3: 第二次交易，持有股票
// j = 4: 第二次交易，不持有股票

// j = 0 时，表示什么都不做，此时利润为 dp[i-1][0]。

// j = 1 时，表示第一次交易持有股票，此时利润为 dp[i-1][0] -
// prices[i]，即在前一天什么都不做的基础上买入股票。 也可以保留前一天的持有状态。
// 也就是 dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])。

// j = 2 时，表示第一次交易不持有股票，此时利润为dp[i-1][1] +
// prices[i]，即在前一天持有股票的基础上卖出股票。也可以保留前一天的持有状态。
// 也就是 dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])。

// j = 3时，表示第二次交易持有股票，此时利润为 dp[i-1][2] -
// prices[i]，即在前一天第一次交易不持有股票的基础上买入股票。
// 也可以保留前一天的持有状态。也就是 dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])。

// j = 4 时，表示第二次交易不持有股票，此时利润为 dp[i-1][3] +
// prices[i]，即在前一天第二次交易持有股票的基础上卖出股票。同上
// 也就是 dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])。

// 初始化
// dp[0][1] = -prices[0] 表示第一天买入股票后，手中的金额为-prices[0]
// dp[0][3] = -prices[0] 表示第一天买入股票后，手中的金额为-prices[0]

// 同一时间只持有一只股票
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

    return dp[prices.size() - 1][4];
}

// 同一时间只持有一只股票
int maxProfivv2(std::vector<int> &prices)
{
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(5, 0));

    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }

    return dp[prices.size() - 1][4];
}
