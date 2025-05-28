#include <algorithm>
#include <numeric>
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

// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

// 1. sub1 == sub2 && sub1 + sub2 = nums
// 2. 可以求得sub1 是多少
// 3. 本题可以转化为，在数组中任选n个值，使它的总和为target

// dp[i][j]  i->{0~n}  j->{0~target}

// dp[i][j]  在容量大小为j的情况下， 在0～i 中任选值的最大和

bool canPartitionv3(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return false;

    int target = std::accumulate(nums.begin(), nums.end(), 0);

    // 如果target % 2 不能0， 那该数组无法分成两份
    if (target % 2 != 0)
    {
        return false;
    }

    target = target / 2;

    std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(target + 1, 0));

    for (int i = nums[0]; i < target + 1; i++)
    {
        dp[0][i] = nums[0];
    }

    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (nums[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
        }
    }

    return dp[nums.size() - 1][target] == target;
}

int main()
{
    std::vector<int> nums{1, 5, 10, 6};
    canPartitionv3(nums);
}