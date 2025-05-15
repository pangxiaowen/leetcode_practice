#include <cstdint>
#include <vector>

int coinChange(std::vector<int> &coins, int amount)
{
    std::vector<int> dp(amount + 1, INT32_MAX);
    dp[0] = 0;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j < amount + 1; j++)
        {
            if (dp[j - coins[i]] != INT32_MAX)
            {
                dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }

    return dp[amount] == INT32_MAX ? -1 : dp[amount];
}