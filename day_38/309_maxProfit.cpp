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

// 状态转移

//    |    ------------------        |
//    v                              |
// 持有股票的状态 -->  进行卖出股票 --> 冷冻期
//    |                              |
//    |                              |
//    v                              v
//  持有股票的状态   <------    保持卖出股票的状态

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

int maxProfitv2(std::vector<int> &prices)
{
    // 下标的含义
    // dp[i][j] 第i天的状态为j时的最大利润
    // 状态j的含义：
    // j = 0: 持有股票
    // j = 1: 当日卖出股票
    // j = 2: 保持卖出股票的状态
    // j = 3: 冷冻期间

    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(4, 0));
    dp[0][0] = -prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        // 持有股票的状态
        // 1. 从前一天持有股票的状态转移过来
        // 2. 从前一天的冷冻期状态转移过来
        // 3. 从前一天的保持卖出股票的状态转移过来

        dp[i][0] =
            std::max(dp[i - 1][0], std::max(dp[i - 1][2], dp[i - 1][3]) - prices[i]); // 持有股票

        dp[i][1] = dp[i - 1][0] + prices[i]; // 卖出股票

        // 保持卖出股票, 或者 从前一天的冷冻期转移过来
        dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][3]);

        // 冷冻期间
        dp[i][3] = dp[i - 1][1]; // 前一天卖出股票，今天是冷冻期
    }

    return std::max(dp[prices.size() - 1][1],
                    std::max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
}
