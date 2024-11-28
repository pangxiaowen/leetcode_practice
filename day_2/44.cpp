#include <iostream>
#include <vector>

int main()
{
    int n = 3; // 行数
    int m = 3; // 列数

    std::vector<std::vector<int>> vec{{3, 1, 2}, {3, 2, 1}, {1, 2, 3}};

    std::vector<std::vector<int>> sums(n + 1, std::vector<int>(m + 1, 0));

    int distance = INT32_MAX;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + vec[i][j];
        }
    }

    int all_sum = sums[n][m]; // 总和

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            int current_dist = abs(all_sum - sums[i + 1][j + 1] * 2);
            distance = distance > current_dist ? current_dist : distance;
        }
    }

    std::cout << distance << std::endl;

    return 0;
}