#include <cstdint>
#include <iostream>
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

int maxSubArrayv2(std::vector<int> &nums)
{
    int result = INT32_MIN;

    // 滑动窗口
    int start = 0;
    int end = 0;
    int currentSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        // 保证窗口内的总和大于0
        while (currentSum < 0 && start <= end)
        {
            currentSum -= nums[start];
            start++;
        }

        currentSum += nums[i];
        end = i;

        if (currentSum > result)
        {
            result = currentSum;
        }
    }

    return result;
}

int maxSubArrayv3(std::vector<int> &nums)
{
    int result = nums[0];
    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (dp[i - 1] > 0)
        {
            dp[i] = dp[i - 1] + nums[i];
        }
        else
        {
            dp[i] = nums[i];
        }

        result = std::max(result, dp[i]);
    }

    return result;
}

int main()
{
    std::vector<int> nums = {5, 4, -1, 7, 8};

    int maxSumV3 = maxSubArrayv3(nums);

    // 输出结果
    std::cout << "Max Subarray Sum V3: " << maxSumV3 << std::endl;

    return 0;
}