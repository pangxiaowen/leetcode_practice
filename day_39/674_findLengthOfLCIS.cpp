#include <vector>

// 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

// 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] <
// nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

// dp[i] 包含第i个元素nums[i]的最长且连续递增的子序列

// 只需要判断前一个元素是否是连续递增的
// if(nums[i] > nums[i-1])
//  dp[i] = dp[i - 1] + 1
// else
//  dp[i] = 1
int findLengthOfLCIS(std::vector<int> &nums)
{
    int result = 0;
    std::vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }

        if (dp[i] > result)
        {
            result = dp[i];
        }
    }

    return result;
}