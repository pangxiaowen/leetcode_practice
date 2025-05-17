#include <vector>

int result;
void Traversal(int i, int j, int m, int n)
{
    // 到达终点
    if (i == m && j == n)
    {
        result++;
        return;
    }

    // 遍历到图外面
    if (i > m || j > n)
    {
        return;
    }

    // 向左移动
    Traversal(i + 1, j, m, n);
    // 向下移动
    Traversal(i, j + 1, m, n);
}

// 超时
int uniquePaths(int m, int n)
{
    Traversal(1, 1, m, n);
    return result;
}

int uniquePathsV2(int m, int n)
{
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    dp[1][1] = 0;

    for (int i = 1; i <= m; i++)
        dp[1][i] = 1;
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;

    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m][n];
}

// 1 确定状态转移数组以及下标的含义
// dp[i][j], 到达 i,j 这个点有多少条路径

// 2. 确定状态转移方程
// dp[i][j] = dp[i-1][j] + dp[i][j-1]

// 3. 确定初始值
// dp[1~m][1] = 1
// dp[1][1~n] = 1
// 如何初始化呢，首先dp[i][0]一定都是1，因为从(0, 0)的位置到(i,
// 0)的路径只有一条，那么dp[0][j]也同理。

// 4. 确定遍历顺序，从小到达遍历