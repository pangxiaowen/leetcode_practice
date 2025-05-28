#include <vector>

int findLength(std::vector<int> &nums1, std::vector<int> &nums2)
{
    // dp[i][j] 以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]。
    // 申请的时候 i = nums1.size() + 1, j = nums2.size() + 1
    // 这样dp[0][0] dp[i][0] dp[0][j] 都是没有意义的，可以直接初始化为0
    // 如果 以下标i为结尾的A，和以下标j为结尾的B，最长重复子数组长度为dp[i][j]。
    // dp[0][0], dp[i][0], dp[0][j] 都是有意义的，需要逐个分情况初始化。

    std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));

    int result = 0;
    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = 1; j <= nums2.size(); j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if (dp[i][j] > result)
            {
                result = dp[i][j];
            }
        }
    }

    return result;
}

int findLengthv2(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::vector<int> dp(nums2.size() + 1, 0);

    int result = 0;
    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = nums2.size(); j > 0; j--)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[j] = dp[j - 1] + 1;
            }
            else
            {
                dp[j] = 0;
            }

            if (dp[j] > result)
            {
                result = dp[j];
            }
        }
    }

    return result;
}

int findLengthv3(std::vector<int> &nums1, std::vector<int> &nums2)
{
    // dp[i][j] 表示以 nums[i-1] 和 nums[j-1] 结尾的最长重复子数组的长度

    // if(nums1[i - 1] == nums2[j -1])
    //  dp[i][j] = dp[i - 1][ j - 1] + 1;
    // else
    //   dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);

    std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));

    // dp[0][j] dp[i][0] 都是没有意义的，所以可以直接初始化为0, 也可以理解为 nums1 和
    // 空的nums2的最长重复子数组长度为0

    // 如果取dp[i][j] 表示以 nums1[i] 和 nums2[j] 结尾的最长重复子数组的长度
    // 则需要初始化dp[0][j], dp[i][0] 都是有意义的， 需要比较nums1[0] 和 nums2
    // 的最长重复子数组长度。

    int result = 0;

    for (int i = 1; i < nums1.size() + 1; i++)
    {
        for (int j = 1; j < nums2.size() + 1; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[nums1.size()][nums2.size()];
}