#include <algorithm>
#include <vector>

// 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
//     你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//     卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

// 状态推导方式，今天卖了， 明天就不能买, 卖出的操作会影响后续

// dp[i][0] 第i天持有股票的最大利润
// dp[i][1] 第i天进行卖出的最大利润
// dp[i][2] 第i天保持卖出的最大利润
// dp[i][3] 第i天处于冷冻期

int maxProfit(std::vector<int> &prices)
{
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(4, 0));

    dp[0][0] = -prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] =
            std::max(dp[i - 1][0], std::max(dp[i - 1][2] - prices[i], dp[i - 1][3] - prices[i]));
        dp[i][1] = dp[i - 1][0] + prices[i]; // 第i天卖出股票的最大利润
        // 第i天不卖出股票由 第i-1天的冷冻期 或者第i-1天的不卖出股票推导出来
        dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][3]);
        dp[i][3] = dp[i - 1][1]; // 第i-1天卖出股票， 第i天是冷冻期
    }

    int end = prices.size() - 1;

    return std::max(dp[end][1], std::max(dp[end][2], dp[end][3]));
}
