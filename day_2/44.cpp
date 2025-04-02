#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    int m = 0;

    std::cin >> n;
    std::cin >> m;

    std::vector<std::vector<int>> vec(m, std::vector<int>(n, 0));

    int sum = 0;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> vec[i][j];
            sum += vec[i][j]; // 计算全部的价值
        }
    }

    std::vector<int> horizontal(n, 0); // 计算横向的价值
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            horizontal[i] += vec[j][i];
        }
    }

    std::vector<int> vertical(n, 0); // 计算纵向的价值
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            vertical[i] += vec[j][i];
        }
    }

    int result = INT_MAX;
    int horizontalCut = 0;
    for (int i = 0; i < n; i++)
    {
        horizontalCut += horizontal[i]; // 纵向划分， 全部的价值-划分出去的 = 剩余的， 剩余的-划分出去的是差值。
        result = std::min(result, abs(sum - horizontalCut - horizontalCut));
    }
    int verticalCut = 0;
    for (int j = 0; j < m; j++)
    {
        verticalCut += vertical[j]; // 横向划分
        result = std::min(result, abs(sum - verticalCut - verticalCut));
    }
    return 0;
}