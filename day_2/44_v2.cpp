#include <climits>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n = 3; // 行数
    int m = 3; // 列数
    std::vector<std::vector<int>> vec{{3, 1, 2}, {3, 2, 1}, {1, 2, 3}};
    int sum = 18;

    // 统计横向
    vector<int> horizontal(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            horizontal[i] += vec[i][j];
        }
    }
    // 统计纵向
    vector<int> vertical(m, 0);
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            vertical[j] += vec[i][j];
        }
    }
    int result = INT_MAX;
    int horizontalCut = 0;
    for (int i = 0; i < n; i++)
    {
        horizontalCut += horizontal[i];
        result = min(result, abs(sum - horizontalCut - horizontalCut));
    }
    int verticalCut = 0;
    for (int j = 0; j < m; j++)
    {
        verticalCut += vertical[j];
        result = min(result, abs(sum - verticalCut - verticalCut));
    }
    cout << result << endl;
}
