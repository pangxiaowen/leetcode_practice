#include <iostream>
#include <vector>

int main()
{
    int n, bag_weight;
    int bag_size = 4;

    std::vector<int> weight{1, 3, 4};
    std::vector<int> value{15, 20, 30};

    // 确定dp数组下标的含义
    // dp[i][j] 在0～i中任选，当背包大小为j时候的 最大价值
    std::vector<std::vector<int>> dp(value.size(), std::vector<int>(bag_size + 1, 0));

    // dp公式
    // dp[i][j] = std::max(dp[i-1][j], dp[i][j - weight[i]] + value[i])

    // 初始化
    // dp[i][0] = 0
    // dp[0][j], 背包大小为j， 尽可能多的放入物品0

    for (int i = 0; i < value.size(); i++)
    {
        dp[i][0] = 0;
    }

    for (int i = weight[0]; i < bag_size + 1; i++)
    {
        dp[0][i] = dp[0][i - weight[0]] + value[0];
    }

    for (int i = 1; i < value.size(); i++)
    {
        for (int j = 0; j < bag_size + 1; j++)
        {
            if (j > weight[i])
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (auto vec : dp)
    {
        for (auto it : vec)
        {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
