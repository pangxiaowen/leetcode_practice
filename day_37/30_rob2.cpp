#include <vector>

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