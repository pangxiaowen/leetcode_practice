#include <vector>

// 直线不能相交，这就是说明在字符串nums1中
// 找到一个与字符串nums2相同的子序列，且这个子序列不能改变相对顺序，只要相对顺序不改变，连接相同数字的直线就不会相交。

// 查找最大公共子序列
// dp[i][j]  i-1 和 j-1 的最大公共子序列

// if(nums1[i-1] == nums[j-1])
//      dp[i][j] = dp[i-1][j-1]
// else
//      dp[i][j] = std::max(dp[i-1][j], dp[i][j-1])

int maxUncrossedLines(std::vector<int> &nums1, std::vector<int> &nums2)
{

    std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));

    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = 1; j < nums2.size(); j++)
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