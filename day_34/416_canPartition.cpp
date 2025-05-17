#include <algorithm>
#include <vector>

bool can = false;

void backtracking(std::vector<int> &nums, std::vector<bool> &used)
{
    int sum_left = 0;
    int sum_rigt = 0;

    for (int i = 0; i < used.size(); i++)
    {
        if (used[i])
        {
            sum_left += nums[i];
        }
        else
        {
            sum_rigt += nums[i];
        }
    }

    if (sum_left == sum_rigt)
    {
        can = true;
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])
            continue;

        used[i] = true;
        backtracking(nums, used);
        used[i] = false;
    }
}

bool canPartition(std::vector<int> &nums)
{
    std::vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return can;
}

bool canPartitionv2(std::vector<int> &nums)
{
    int target = 0;
    // 计算总和
    for (auto it : nums)
    {
        target += it;
    }

    // 如果target % 2 不能0， 那该数组无法分成两份
    if (target % 2 != 0)
    {
        return false;
    }

    target = target / 2;

    // 将本题进行转化，求是否能找到一组数字，使它的和为target
    // 能否将容量为target的背包填满。
    std::vector<int> dp(target + 1, 0);
    std::vector<int> weights = nums;
    std::vector<int> values = nums;

    for (int i = 0; i < weights.size(); i++) // 遍历每一个物品
    {
        for (int j = target; j >= weights[i]; j--)
        {
            dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    return dp[target] == target;
}