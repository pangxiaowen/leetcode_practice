#include <cstdint>
#include <vector>

int maxProfit(std::vector<int> &prices)
{
    int value = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[j] - prices[i] < 0)
            {
                break;
            }
            value = std::max(value, prices[j] - prices[i]);
        }
    }

    return value;
}

int maxProfitv2(std::vector<int> &prices)
{
    int low = INT32_MAX;
    int value = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        low = std::min(low, prices[i]);
        value = std::max(value, prices[i] - low);
    }

    return value;
}

int maxProfitv3(std::vector<int> &prices)
{
    // 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
    // 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子
    // 卖出该股票。设计一个算法来计算你所能获取的最大利润。
    // 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

    // dp[i][0] 0～i天中持有股票，手中现金的最大金额
    // dp[i][1] 0～i中卖出股票，卖出股票时的最大利润。

    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));

    dp[0][0] = -prices[0]; // 第0天的时候，买入股票手中的最大金额
    dp[0][1] = 0;          // 第0天的时候，卖出股票时的最大利润。

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = std::max(dp[i - 1][0], -prices[i]);               // 记录股票的最底值
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]); // 卖掉股票的最大利润
    }

    return dp[prices.size() - 1][1];
}

int maxProfitv4(std::vector<int> &prices)
{
    // 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
    // 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子
    // 卖出该股票。设计一个算法来计算你所能获取的最大利润。
    // 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

    // dp[i][0] 0～i天中持有股票，手中现金的最大金额
    // dp[i][1] 0～i中卖出股票，卖出股票时的最大利润。

    std::vector<std::vector<int>> dp(2, std::vector<int>(2, 0));

    dp[0][0] = -prices[0]; // 第0天的时候，买入股票手中的最大金额
    dp[0][1] = 0;          // 第0天的时候，卖出股票时的最大利润。

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i % 2][0] = std::max(dp[(i - 1) % 2][0], -prices[i]); // 记录股票的最底值
        dp[i % 2][1] =
            std::max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]); // 卖掉股票的最大利润
    }

    return dp[(prices.size() - 1) % 2][1];
}