#include <vector>

// 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee
// 代表了交易股票的手续费用。
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
// 返回获得利润的最大值。
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

//

// dp[i][0] 持有股票的最大利润
//      1. 前一天就持有  2. 前一天卖出股票， 今天买入
// dp[i][1] 不持有股票的最大利润
//      1. 前一天就不持有股票   2. 前一天持有股票，今天卖出

// dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i])
// dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] + prices[i] - fee)

int maxProfit(std::vector<int> &prices, int fee)
{

    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));

    dp[0][0] = -prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }

    return std::max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
}

int maxProfitv2(std::vector<int> &prices, int fee)
{

    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(3, 0));

    // 第一天只进行买入，不进行卖出，否则一定会亏手续费
    dp[0][0] = -prices[0]; // dp[i][0] 持有股票的最大利润
    dp[0][1] = 0;          // 不持有股票的最大利润， 不进行卖出
    dp[0][2] = 0;          // 卖出股票的最大利润

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = std::max(dp[i - 1][0], std::max(dp[i - 1][1], dp[i - 1][2]) - prices[i]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][2] = dp[i - 1][0] + prices[i] - fee;
    }

    return std::max(std::max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]),
                    dp[prices.size() - 1][2]);
}

int main()
{
    std::vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    maxProfit(prices, fee);

    return 0;
}