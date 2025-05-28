#include <cstdint>
#include <vector>

// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 注意：给定 n 是一个正整数。

// 下标含义
// dp[j] 的含义是到达 j 阶有多少种不同的方式。

// PD公式
// dp[j] += dp[j -w[i]]

// 遍历顺序
// 有多少种不同的方式爬楼梯（1, 2) 和 (2, 1) 是不同的方式
// 因此要先遍历背包，再遍历物品
// for(n)
//     for(m)

int run(int n, std::vector<int> &weight)
{
    // dp下标的含义
    // dp[j]， 到j阶有多少种不同的方式

    std::vector<int> dp(n + 1, 0);

    // dp公式
    // dp[j] += dp[j - w[i]]

    // 初始化
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < weight.size(); j++)
        {
            if (i >= weight[i])
                dp[i] += dp[i - weight[i]];
        }
    }

    return dp[n];
}