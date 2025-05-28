#include <vector>

// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下
// 一夜之内能够偷窃到的最高金额。

// 下标含义
// dp[j] 的含义是偷到第 j 个房间时能够获取的最高金额。

// DP 公式

// 前一个房间偷了， 当前房间不偷
// 前一个房间没偷， 当前房间偷
// dp[j] = max(dp[j-1], dp[j-2] + nums[j])

// 遍历顺序
// 从前到后遍历房间

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

int rob_(std::vector<int> &nums)
{
    // dp[j] 偷到第j个房间的时候能够获取的最高金额
    std::vector<int> dp(nums.size() + 1, 0);

    // dp[0] = 0;
    dp[1] = nums[0];                    // 偷第一个房间获得的金额
    dp[2] = std::max(nums[0], nums[1]); // 偷第二个房间获取的最大金额

    for (int i = 3; i < nums.size(); i++)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        // dp[i - 1], 偷到第j - 1个房间的时候能够获取的最高金额
        // dp[i - 2] + nums[i], 偷到第j - 2个房间的时候能够获取的最高金额 + 当前房间的金额
    }

    return dp[nums.size()];
}

int rob__(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums.size() == 0 ? 0 : nums[0];

    // dp[j] 偷到第j个房间的时候能够获取的最高金额
    std::vector<int> dp(2, 0);

    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]); // 和偷第二个房间获取的最大金额

    for (int i = 2; i < nums.size(); i++)
    {
        dp[i % 2] = std::max(dp[(i - 1) % 2], dp[(i - 2) % 2] + nums[i]);
    }

    return dp[0] > dp[1] ? dp[0] : dp[1];
}