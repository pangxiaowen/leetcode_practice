#include <string>
#include <vector>

// 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
// 请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

// 下标含义
// dp[i][j] 含有i和0 和 n 个 1的 最大子集大小

// DP公式
// dp[i][j] = std::max(dp[i][j], dp[i - zero_nums][j - one_nums] + 1])

// 初始化
// dp[0][0] = 0;

// 遍历顺序
// 1. 遍历strs
// 2. 从m,n开始遍历到 i >= zero_nums 和 j >= one_nums

// 最多 有 m 个 0 和 n 个 1 。
int acl_zero_nums(std::string &str)
{
    int res = 0;
    for (auto it : str)
    {
        if (it == '0')
        {
            res++;
        }
    }

    return res;
}

int acl_one_nums(std::string &str)
{
    int res = 0;
    for (auto it : str)
    {
        if (it == '1')
        {
            res++;
        }
    }

    return res;
}

int findMaxForm(std::vector<std::string> &strs, int m, int n)
{
    int res = 0;

    // dp 数组下标的含义
    // dp[i][m][n], 0~i子集，在背包容量为m, n的最大长度。
    std::vector<std::vector<std::vector<int>>> dp(
        strs.size(), std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0)));

    // dp 公式
    // dp[i][m][n] =std::max(dp[i-1][m][n], dp[i][m - zero_nums][n - one_nums] + 1)

    // 初始化
    // 当m == 0 n == 0 是， 0～i 都是0

    // 当 i = 0 时， 根据 strs[0]的情况进行初始化
    int first_zero_num = acl_zero_nums(strs[0]);
    int first_one_num = acl_one_nums(strs[0]);
    for (int i = first_zero_num; i < m + 1; i++)
    {
        for (int j = first_one_num; j < n + 1; j++)
        {
            dp[0][i][j] = 1;
        }
    }

    for (int i = 1; i < strs.size(); i++)
    {
        int zero_num = acl_zero_nums(strs[i]);
        int one_num = acl_one_nums(strs[i]);

        for (int j = 0; j < m + 1; j++)
        {
            for (int k = 0; k < n + 1; k++)
            {
                if (j < zero_num || k < one_num)
                    dp[i][j][k] = dp[i - 1][j][k];
                else
                    dp[i][j][k] =
                        std::max(dp[i - 1][j][k], dp[i - 1][j - zero_num][k - one_num] + 1);
            }
        }
    }

    return dp[strs.size() - 1][m][n];
}

int findMaxForm_(std::vector<std::string> &strs, int m, int n)
{
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i < strs.size(); i++)
    {
        int zero_nums = acl_zero_nums(strs[i]);
        int one_nums = acl_one_nums(strs[i]);

        for (int j = m; j >= zero_nums; j--)
        {
            for (int k = n; k >= one_nums; k--)
            {
                dp[j][k] = std::max(dp[j][k], dp[j - zero_nums][k - one_nums] + 1);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    std::vector<std::string> strs{"0", "0", "1", "1"};
    findMaxForm_(strs, 2, 2);
}