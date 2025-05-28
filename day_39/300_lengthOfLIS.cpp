#include <algorithm>
#include <vector>

// 对于最长递增子序列（LIS）问题，动态规划是一种直观但时间复杂度较高的解法。
//它的核心思想是通过记录以每个位置结尾的最长递增子序列长度，逐步推导出全局最优解。以下是具体步骤：

// dp[i], 以第i个元素nums[i]为结尾的最长递归子序列

// dp公式
// 对于每个元素 nums[i]，我们需要检查它之前的所有元素 nums[j]（j < i）：
// 如果 nums[i] > nums[j]，则 nums[i] 可以接在 nums[j] 结尾的子序列后面，形成更长的递增子序列。
// 因此，状态转移方程为：
// dp[i] = max(dp[i], dp[j] + 1)
// （对所有 j < i 且 nums[i] > nums[j] 的情况取最大值）

// 初始化
// 每个元素本身至少可以形成一个长度为 1 的子序列，因此初始化 dp[i] = 1（对所有 i）。

int lengthOfLIS(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums.size();

    std::vector<int> dp(nums.size(), 1);

    int result = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        if (dp[i] > result)
        {
            result = dp[i];
        }
    }

    return result;
}

int lengthOfLISv2(std::vector<int> &nums)
{
    std::vector<int> tails; // 保证tails中，最后一个元素尽可能的小，这样后续才能有更多的可能性。

    for (auto nums : nums)
    {
        auto it = std::lower_bound(tails.begin(), tails.end(), nums); // 找到大于等于nums的第一个值

        if (it == tails.end())
        {
            tails.push_back(nums); // 如果it比所有的值都大，这插入这个值
        }
        else
        {
            *it = nums; // 更新it处的值
        }
    }

    return tails.size();
}

// 10   9   2   5   3   7   101   18
// 1    1   1   1   1   1   1     1
// 1    1   1   2   2   2   2     2
//                  2   3   3     3
//                      3   4     4
//                          4     4

int lengthOfLISv3(std::vector<int> &nums)
{
    // 下标含义
    // dp[j] 包含nums[j]的最大子序列长度
    // if(nums[i] > nums[j])
    //  dp[i] = std::max(dp[i], dp[j] + 1);

    std::vector<int> dp(nums.size(), 1);

    int maxLength = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] > nums[i])
            {
                dp[j] = std::max(dp[j], dp[i] + 1);
            }

            if (dp[j] > maxLength)
            {
                maxLength = dp[j];
            }
        }
    }

    return maxLength;
}

int lengthOfLISv4(std::vector<int> &nums)
{
    std::vector<int> result;
    result.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > result.back())
        {
            result.push_back(nums[i]);
        }
        else
        {
            nums[nums.size() - 1] = nums[i];
        }
    }

    return result.size();
}