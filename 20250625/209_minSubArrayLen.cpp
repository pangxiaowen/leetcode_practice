
#include <algorithm>
#include <cstdint>
#include <vector>

// 给定一个含有 n 个正整数的数组和一个正整数 target 。
// 找出该数组中满足其总和大于等于 target 的长度最小的
//  [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

// // 滑动窗口 这种方法是寻找和为target的连续字符串的最小长度
int minSubArrayLen(int target, std::vector<int> &nums)
{
    int sum = 0;
    int start = 0;
    int len = INT32_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        while (sum >= target && i >= start)
        {
            len = std::min(len, (i - start + 1));
            sum -= nums[start];
            start++;
        }
    }

    return len == INT32_MAX ? 0 : len;
}

int main()
{
    int target = 213;
    std::vector<int> nums = {12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
    minSubArrayLen(target, nums);
}