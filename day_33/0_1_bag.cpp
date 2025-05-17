#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    // 确认DP数组下标的含义
    // dp[i][j], 0~i 物体任意选， 在j重量下的最大价值

    // 确认DP公式
    // dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - w[i]] + v[i])
    // 获取dp[i][j] 有两种方式
    // 1. 不选i，那结果和dp[i-1][j] 相同
    // 2. 选i, 那j要减去i的重量， j - w[i], 加上i的价值 v[i]

    // 初始化
    // 当背包大小为0是， 什么都不选 dp[i][0] = 0;
    // 当仅选第一个物品时， dp[0][j], 根据j和w[0]的大小进行初始化

    // 遍历顺序确认
    // 先遍历物体或者背包都可以

    int obj_nums = 4;  // 4个物品
    int bag_size = 10; // 背包大小为10

    std::vector<int> weight{1, 2, 3, 4};
    std::vector<int> value{1, 2, 3, 4};

    std::vector<std::vector<int>> dp(4, std::vector<int>(10, 0));

    for (int i = 0; i < obj_nums; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i < bag_size; i++)
    {
        if (i >= weight[0])
        {
            dp[0][i] = value[0];
        }
        else
        {
            dp[0][i] = 0;
        }
    }

    for (int i = 1; i < obj_nums; i++)
    {
        for (int j = 1; j < bag_size; j++)
        {
            if (j >= weight[i])
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i < obj_nums; i++)
    {
        for (int j = 0; j < bag_size; j++)
        {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
}