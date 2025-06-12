#include <vector>

int maxProfit(std::vector<int> vals)
{
    int result = 0;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        int val = vals[i] - vals[i - 1];
        if (val > 0)
        {
            result += val;
        }
    }

    return result;
}

int maxProfitv2(std::vector<int> vals)
{
    std::vector<std::vector<int>> dp(vals.size(), std::vector<int>(2, 0));

    dp[0][0] = -vals[0];
    dp[0][1] = 0;

    for (int i = 1; i < vals.size(); i++)
    {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - vals[i]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + vals[i]);
    }

    return dp[vals.size() - 1][1];
}

int maxProfitv3(std::vector<int> prices)
{
    int result = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        int val = prices[i] - prices[i - 1];

        if (val > 0)
        {
            result += val;
        }
    }

    return result;
}
