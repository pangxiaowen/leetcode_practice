#include <cmath>
#include <math.h>
#include <numeric>
#include <vector>

int numTrees(int n)
{
    std::vector<int> dp(n + 1, 0);

    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}