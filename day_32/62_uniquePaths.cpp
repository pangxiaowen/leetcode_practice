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

    dp[1][1] = 1;

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

// 下标含义
// dp[i][j] 到达i，j 这个点有多少路径

// DP公式，由于每次只能向下或者向右移动一步
// dp[i][j] = dp[i-1][j] + dp[i][j-1]

// 初始化
// dp[0][0] = 1
// dp[i][0] = 1 一直向下，只有一条路径
// dp[0][i] = 1 一直向右，只有一条路径

// 遍历顺序
// 由于i，j 由 (i-1, j) 和 (i, j-1) 推导出来， 所以 0～i, 0~j 这个顺序遍历

// 举例
// dp[1][1] = dp[0][1] + dp[1][0]  向左再向下， 向下再向左