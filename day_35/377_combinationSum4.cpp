// 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

// 下标含义
// dp[i][j] 表示前 i 个数能组成 j 的组合数

// DP 公式
// dp[i-1][j] 表示不选第 i 个数的情况
// dp[i][j - nums[i]] 表示选第 i 个数的情况
// 所以状态转移方程为
// dp[i][j] = dp[i-1][j] + dp[i][j- nums[i]]

// 初始化
// dp[i][0] = 1 表示和为 0 的组合数为 1（即不选任何数）
// dp[0][i] = ？ 表示第一个数字能够组成的和为 i 的组合数

#include <cstdint>
#include <iostream>
#include <vector>

int combinationSum4(std::vector<int> &nums, int target)
{
    std::vector<std::uint64_t> dp(target + 1, 0);

    dp[0] = 1; // 和为 0 的组合数为 1（即不选任何数）
    for (int i = 1; i < target + 1; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i >= nums[j])
            {
                dp[i] += dp[i - nums[j]];
            }
        }
    }

    return dp[target];
}