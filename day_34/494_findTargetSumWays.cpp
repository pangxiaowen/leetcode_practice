#include <algorithm>
#include <math.h>
#include <numeric>
#include <vector>

// 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和
// -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
// 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

// 将数组分为两部分，
// sub1 - sub2 = target
// sub1 + sub2 = sum
// 2 * sub1 = target + sum
// sub1 = (target + sum) / 2
// sub1 必须是整数， 所以 如果 sub1 % 2 != 0 则returen 0
// 本题转化为，在数组中选一些数字，使他们的和是 (target + sum) / 2

int findTargetSumWays(std::vector<int> &nums, int target)
{
    // 分成两个数组，他们的差值是target
    int sum = 0;
    for (auto it : nums)
    {
        sum += it;
    }

    if ((sum + target) % 2 != 0)
        return 0;

    if (std::abs(target) > sum)
        return 0;

    // 从nums里面选一些值， 是他们的和为val. 这些值前面加+， 其他值为-
    int val = (sum + target) / 2;

    // 我们需要求解， 装满大小是val的背包有多少种办法
    std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(val + 1, 0));
    // dp[i][j], 从0～i 里面任意选， 能够有几种方法填满大小为j的背包。

    // 如果 i == nums[0], 此时nums[0]可以填满背包。
    for (int i = 0; i < val + 1; i++)
    {
        if (i == nums[0])
        {
            dp[0][i] = 1;
        }
    }

    dp[0][0] = 1;

    // 初始化， 背包大小为0时，不放任何物体，填满背包，只有这一种情况。
    // 要考虑nums[i] == 0的情况
    int zero_num = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            zero_num++;
        dp[i][0] = static_cast<int>(std::pow(2.0, zero_num));
    }

    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < val + 1; j++)
        {
            if (j >= nums[i])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[nums.size() - 1][val];
}

int findTargetSumWaysv2(std::vector<int> &nums, int target)
{
    // 分成两个数组，他们的差值是target
    int sum = std::accumulate(nums.begin(), nums.end(), 0);

    // 如果sum + target 为奇数则不能分成两个子集
    if ((sum + target) % 2 != 0)
        return 0;

    // 如果target 比 目标和还要大，则无解
    if (std::abs(target) > sum)
        return 0;

    // 从nums里面选一些值， 是他们的和为val. 这些值前面加+， 其他值为-
    int val = (sum + target) / 2;

    // 我们需要求解， 装满大小是val的背包有多少种办法
    std::vector<int> dp(val + 1, 0);

    // 初始化
    int zero_num = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zero_num++;
        }
    }

    // 装满背包大小为0的背包有多少种方法。
    dp[0] = std::pow(2, zero_num);

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = val; j >= nums[i]; j--)
        {
            dp[j] = dp[j] + dp[j - nums[i]];
        }
    }

    return dp[val];
}

int main()
{
    std::vector<int> nums{0};
    findTargetSumWays(nums, 0);
}