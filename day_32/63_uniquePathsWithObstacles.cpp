#include <vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        // 如果障碍物在边上，障碍物后面的点都是不可达点
        if (obstacleGrid[i][0] == 1)
        {
            dp[i][0] = 0;
            break;
        }
        else
            dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        // 如果障碍物在边上，障碍物后面的点都是不可达点
        if (obstacleGrid[0][i] == 1)
        {
            dp[0][i] = 0;
            break;
        }
        else
            dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            // 如果有障碍物那么到达该点的路径为0
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}