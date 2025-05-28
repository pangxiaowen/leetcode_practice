#include <bits/stdint-uintn.h>
#include <cstdint>
#include <iostream>
#include <vector>

int change(int amount, std::vector<int> &coins)
{
    // 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
    // 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

    // 转化为完全背包问题
    // 一个背包大小为amount, 从conins选硬币， 都多少种方式将背包装满。

    // 确认下标的含义
    // dp[i][j] 从0～i中选， 当背包大小为j的时候，有多少种方式装满

    // dp公式
    // dp[i][j] = dp[i - 1][j] + dp[i][j - conis[i]]

    // 初始化
    // dp[i][0] = 1
    // dp[0][i] = 1 当背包大小为i时， 如果i % coins[0] == 0, 说明使用物品0能将背包装满，方案数量为1

    std::vector<std::vector<std::uint64_t>> dp(coins.size(),
                                               std::vector<std::uint64_t>(amount + 1, 0));

    for (int i = 0; i < coins.size(); i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 0; i < amount + 1; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < coins.size(); i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            if (j >= coins[i])
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[coins.size() - 1][amount];
}

int changev2(int amount, std::vector<int> &coins)
{
    // 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
    // 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

    // 转化为完全背包问题
    // 一个背包大小为amount, 从conins选硬币， 都多少种方式将背包装满。

    // 确认下标的含义
    // dp[j] 当背包大小为j的时候，有多少种方式装满

    // dp公式
    // dp[j] += dp[j - coins[i]];

    // 初始化
    // dp[j] = 1

    std::vector<uint64_t> dp(amount + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            if (j >= coins[i])
            {
                dp[j] += dp[j - coins[i]];
                std::cout << "index: " << j << " v: " << dp[j] << std::endl;
            }
        }
    }

    return dp[amount];
}

int changev3(int amount, std::vector<int> &coins)
{

    std::vector<uint64_t> dp(amount + 1, 0);

    dp[0] = 1;

    for (int j = 0; j < amount + 1; j++)
    {
        for (int i = 0; i < coins.size(); i++)
        {
            if (j >= coins[i])
            {
                dp[j] += dp[j - coins[i]];
                std::cout << "index: " << j << " v: " << dp[j] << std::endl;
            }
        }
    }

    return dp[amount];
}

// 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

// 下标的含义
// dp[i] 总金额为i时，凑成总金额的的硬币组合数

// DP公式
// dp[i] += dp[i - conins[j]]

// 初始化
// dp[0] = 1;

// 遍历顺序
// 1. 遍历coins
// 2. 遍历amount
// 3. 当amount >= coins[i]时， dp[amount] += dp[amount - coins[i]];
// 4. 返回dp[amount]
// 5. 注意： coins[i]可以重复使用， 所以遍历顺序不能是amount -> coins[i]， 否则会导致重复计算。

int changev4(int amount, std::vector<int> &coins)
{
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j < amount + 1; j++)
        {
            // dp[j] += dp[j - coins[i]];

            std::cout << "i: " << i << " j: " << j << " dp[j]: " << dp[j] << std::endl;
        }
    }

    for (int i = 0; i < amount + 1; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i >= coins[j])
            {
                // dp[j] += dp[j - coins[i]];
                std::cout << "i: " << i << " j: " << j << " dp[j]: " << dp[j] << std::endl;
            }
        }
    }

    return dp[amount];
}

int main()
{
    std::vector<int> coins{1, 2, 5};
    // changev2(5, coins);
    // std::cout << "!!!!!!!!!!!!" << std::endl;
    // changev3(5, coins);

    changev4(5, coins);
    return 0;
}
