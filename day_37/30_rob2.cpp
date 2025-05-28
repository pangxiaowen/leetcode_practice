#include <vector>

// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
// ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
// 。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下
// ，能够偷窃到的最高金额。

// 本题的额外条件是房屋围成一圈，因此第一个房屋和最后一个房屋不能同时被偷。
// 因此，我们可以将问题分为两种情况：
// 1. 偷第一个房屋，不偷最后一个房屋。此时访问的访问是[start, end - 1]。
// 2. 不偷第一个房屋，偷最后一个房屋。此时访问的范围是[start + 1, end]。
// 我们可以分别计算这两种情况的最大金额，然后取两者的最大值。

int robRange(std::vector<int> &nums, int start, int end)
{
    if (nums.size() == 1)
        return nums[0];

    std::vector<int> dp(end - start + 1, 0);
    dp[0] = nums[start];
    dp[1] = std::max(nums[start], nums[start + 1]);

    for (int i = 2; i < dp.size(); i++)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[start + i]);
    }

    return dp[dp.size() - 1];
}

int rob(std::vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    int res_1 = robRange(nums, 0, nums.size() - 2);
    int res_2 = robRange(nums, 1, nums.size() - 1);

    return std::max(res_1, res_2);
}