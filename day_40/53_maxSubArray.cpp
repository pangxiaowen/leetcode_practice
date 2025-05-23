#include <cstdint>
#include <vector>

// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// dp[i] 数组大小是i时候的连续子数组的最大和

// dp[i-1] 如果大于0, 则说明他对后面的结果有正收益， 如果小于0, 则说明有负收益， 直接放弃。
// if(dp[i-1] < 0)
//   dp[i] = nums[i]
// else
//   dp[i] = dp[i-1] + nums[i]

//      -1  4  -3  7
//      -1  4   1  8

//      -2  1 -3  4  -1  2  1 -5  4
//      -2  1 -2  4  3   5  6  1  5

//      5  4 -1 7  8
//      5  9  8 15 23

int maxSubArray(std::vector<int> &nums)
{
    std::vector<int> dp(nums.size(), 0);

    dp[0] = nums[0];

    int result = dp[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (dp[i - 1] < 0)
        {
            dp[i] = nums[i];
        }
        else
        {
            dp[i] = dp[i - 1] + nums[i];
        }

        if (dp[i] > result)
        {
            result = dp[i];
        }
    }

    return result;
}