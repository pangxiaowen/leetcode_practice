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

int main()
{
    std::vector<int> coins{1, 2, 5};
    changev2(5, coins);
    std::cout << "!!!!!!!!!!!!" << std::endl;
    changev3(5, coins);
}
