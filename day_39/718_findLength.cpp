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