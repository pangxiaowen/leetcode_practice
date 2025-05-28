#include <vector>

// 下标含义
// dp[i][j] 到达i，j 这个点有多少条路径

// dp公式
// dp[i][j] = dp[i-1][j] + dp[i][j-1]

// 初始化
// dp[0][0] = 1 到达0,0点只有一条路径，

// 由于存在障碍物，如果x，y 位置有障碍物，则遇到dp[x][y]的时候 dp[x][y] = 0, 障碍物所在位置无法到达

// dp[0][i] = 1, 如果障碍物在边上，则障碍物后面的位置都无法到达
// dp[i][0] = 1, 同上

// 遍历顺序
// (i,j) 由(i-1, j), (i, j-1) 推出来， 因此 0~i, 0~j 的遍历顺序

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