#include <cstdint>
#include <vector>

// 给定不同面额的硬币 coins 和一个总金额
// amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回
// -1。

// 你可以认为每种硬币的数量是无限的。

// 下标含义
// dp[i] 的含义是凑成金额 i 所需的最少硬币个数。

// PD公式
// dp[j] = min(dp[j], dp[j - coins[i]] + 1)

// dp[0]= 0，表示凑成金额 0 不需要任何硬币。

// 遍历顺序
// 外层循环遍历硬币 coins，内层循环遍历金额 j，从 coins[i] 到 amount。

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

int coinChange_(std::vector<int> &coins, int amount)
{
    std::vector<std::vector<int>> dp(coins.size(), std::vector<int>(amount + 1, INT32_MAX));

    for (int i = 0; i < coins.size(); i++)
    {
        dp[i][0] = 0; // 凑成金额 0 不需要任何硬币
    }

    for (int i = 0; i < amount + 1; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = i / coins[0]; // 使用第一个硬币凑成金额 i
        }
    }

    for (int i = 1; i < coins.size(); i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (j >= coins[i])
            {
                dp[i][j] = std::min(dp[i - 1][j],
                                    dp[i][j - coins[i]] == INT32_MAX ? INT32_MAX
                                                                     : dp[i][j - coins[i]] + 1);
            }
            else
            {
                dp[i][j] = dp[i - 1][j]; // 不使用当前硬币
            }
        }
    }

    return dp[coins.size() - 1][amount] == INT32_MAX ? -1 : dp[coins.size() - 1][amount];
}