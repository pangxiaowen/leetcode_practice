#include <iostream>
#include <vector>

int main()
{
    int n, bag_weight;
    int bag_size = 4;

    std::vector<int> weight{1, 3, 4};
    std::vector<int> value{15, 20, 30};

    // 确定dp数组下标的含义
    // dp[j] 当背包大小为j时候的 最大价值
    std::vector<int> dp(bag_size + 1, 0);

    // dp公式
    // dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i])

    // 初始化
    // dp[j] = 0

    // 遍历方式
    for (int i = 0; i < weight.size(); i++)
    {
        for (int j = 0; j < bag_size + 1; j++)
        {
            if (j >= weight[i])
                dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    for (auto it : dp)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}
