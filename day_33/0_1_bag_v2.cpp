#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    // 使用1维的DP数组

    // 确认DP数组下标的含义
    // dp[j], 背包容量为j时的最大价值

    // 确认DP公式
    // dp[j] = std::max(dp[j], dp[j-w[i]] + v[i])
    // 获取dp[j] 有两种方式
    // 1. 不选物体i，那结果不变
    // 2. 选物体i, 那要减去i的重量， j - w[i], 加上j的价值 v[i]

    // 初始化
    // 初始化为0即可

    // 遍历顺序确认
    // 先遍历物体，再遍历背包
    // 背包大小要从后往前遍历。否则物体会被放入背包多次。因为如果j-w[i] > 0,
    // 那v[i]就会被放入背包，无论之前是否放入过。

    int obj_nums = 4;  // 4个物品
    int bag_size = 10; // 背包大小为10

    std::vector<int> weight{1, 2, 3, 4};
    std::vector<int> value{1, 2, 3, 4};

    std::vector<int> dp(10, 0);

    for (int i = 0; i < obj_nums; i++)
    {
        for (int j = bag_size - 1; j >= weight[i]; j--)
        {
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    for (auto it : dp)
    {
        std::cout << it << std::endl;
    }
}