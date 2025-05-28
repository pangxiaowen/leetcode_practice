#include <algorithm>
#include <vector>

// 有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

// 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <=
// y。那么粉碎的可能结果如下：

//     如果 x == y，那么两块石头都会被完全粉碎；
//     如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。

// 最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0

// 本题其实是尽量让石头分成重量相同的两堆（尽可能相同），相撞之后剩下的石头就是最小的。

int lastStoneWeightII(std::vector<int> &stones)
{
    // 如何转化为背包问题
    // 将石头分成差值尽可能小的两个堆。

    int sum = 0;
    for (auto it : stones)
    {
        sum += it;
    }
    int target = sum / 2;

    // 一个容量为target的背包，尽可能的多装元素。
    std::vector<int> dp(target + 1, 0);
    for (int i = 0; i < stones.size(); i++)
    {
        for (int j = target; j >= stones[i]; j--)
        {
            dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }

    return sum - 2 * dp[target];
}

int lastStoneWeightII_(std::vector<int> &stones)
{
    // 如何转化为背包问题
    // 将石头分成差值尽可能小的两个堆。

    int sum = 0;
    for (auto it : stones)
    {
        sum += it;
    }
    int target = sum / 2;

    // 一个容量为target的背包，尽可能的多装元素。
    std::vector<int> dp(target + 1, 0);

    for (int i = 0; i < stones.size(); i++)
    {
        for (int j = target; j >= stones[i]; j--)
        {
            dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }

    return sum - 2 * dp[target];
}