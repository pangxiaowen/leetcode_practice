#include <iostream>
#include <vector>

// 暴力解法， 两个for循环, 对每一个元素，逐个与后续元素进行累加, 当累加和大于目标值的时候,
// 结束当前值的累加，并记录此时的长度, 与历史的长度进行比较，判断是否为最小值
int minSubArrayLen(std::vector<int> nums, int targer)
{
    int result = __INT32_MAX__;
    int sum = 0;
    int subLength = 0;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        sum = 0;
        for (size_t j = i; j < nums.size(); ++j)
        {
            sum = sum + nums[j];
            if (sum >= targer)
            {
                subLength = j - i + 1;
                result = result < subLength ? result : subLength;
                break;
            }
        }
    }

    return result == __INT32_MAX__ ? 0 : result;
}

int minSubArrayLen_v2(std::vector<int> nums, int target)
{
    int result = INT32_MAX; // 用于记录历史最小的长度
    int subLength = 0;      // 用于记录字串长度

    for (size_t i = 0; i < nums.size(); ++i)
    {
        int sum = 0; // 用于记录子串和
        for (size_t j = i; j < nums.size(); ++j)
        {
            sum = sum + nums[j]; // 计算字串和
            if (sum > target)    // 子串和大于目标值,尝试更新result
            {
                subLength = j - i;
                result = result > subLength ? subLength : result;
                break; // 当子串和大于目标值，后续的值无需计算
            }
        }
    }

    return result == INT32_MAX ? 0 : result; //  result == INT32_MAX 为没有匹配到相应的子串
}

// 滑动窗口
// 什么条件下增大滑动窗口
// 什么条件下收缩滑动窗口
// 收缩滑动窗口的时候, 记录窗口的大小
int minSubArrayLen_v3(std::vector<int> nums, int target)
{
    int result = INT32_MAX;
    int sum = 0;

    int left = 0;
    int right = 0;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        sum = sum + nums[i];
        while (sum >= target) // 若子串和大于目标值, 通过减去左边的值, 让sum回到一个小于target的状态
        {
            result = result < (right - left + 1) ? result : (right - left + 1); // 当sum > targer的时候, 触发更新result
            sum = sum - nums[left];
            left++; // left不断往右边移动, 直到sum小于target, 也就是left和right之间的值的和小于target
        }

        right++;
    }

    return result == INT32_MAX ? 0 : result; //  result == INT32_MAX 为没有匹配到相应的子串
}

int minSubArrayLen_v4(std::vector<int> nums, int target)
{
    int result = INT32_MAX;
    int sum = 0;
    int i = 0;
    int sublength = 0;

    // 可以看成双指针 i是左指针 j是右指针 要保证i~j之间的和小于target
    for (int j = 0; j < nums.size(); ++j)
    {
        sum += nums[j];
        while (sum >= target)
        {
            sublength = j - i + 1;
            result = result < sublength ? result : sublength;
            sum -= nums[i++];
        }
    }

    return result == INT32_MAX ? 0 : result;
}

int main()
{
    std::vector<int> nums{2, 3, 1, 2, 4, 3};
    std::cout << minSubArrayLen_v4(nums, 7) << std::endl;
    return 0;
}