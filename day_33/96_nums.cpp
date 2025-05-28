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
        for (int j = 1; j <= i; j++) // 以j为头节点
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

// n = 1

//  1

// n = 2

//  1        2
//   \      /
//    2    1

// n = 3
//  1            2        1      ...
//   \          / \        \  
//    2       1     3       3
//     \                   /
//      3                 2

// 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

// 下标含义
// dp[i], 以整数i为节点组成的二叉搜索树有多少种

// DP公式
// 对于整数n
// 以n为头节点， 左子树木有n-1个节点， 右子树有0个节点
// 以n-1 为头节点，左子树木有n-2个节点， 右子树有1个节点

// dp[n] = dp[n-1]*dp[0] + dp[n-2]* dp[1] ....

// 遍历顺序
// 由于n是由 n-i 和 i 推导出来，因此从小到大遍历