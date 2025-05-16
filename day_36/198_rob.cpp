#include <vector>

// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下
// 一夜之内能够偷窃到的最高金额。

int rob(std::vector<int> &nums)
{
    // dp[j] 偷到第j个房间的时候能够获取的最高金额
    std::vector<int> dp(nums.size() + 1, 0);

    // dp[0] = 0;
    dp[1] = nums[0];
    dp[2] = std::max(nums[0], nums[1]);

    for (int i = 3; i < nums.size(); i++)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        // dp[i - 1], 偷到第j - 1个房间的时候能够获取的最高金额
        // dp[i - 2] + nums[i], 偷到第j - 2个房间的时候能够获取的最高金额 + 当前房间的金额
    }

    return dp[nums.size()];
}