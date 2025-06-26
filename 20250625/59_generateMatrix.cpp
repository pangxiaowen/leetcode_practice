#include <vector>

// 输入：n = 3
// 输出：[[1,2,3],[8,9,4],[7,6,5]]

//  1  2  3
//  8  9  4
//  7  6  5

// 1  2  3  4
// 12 13 14 5
// 11 16 15 6
// 10 9  8  7
std::vector<std::vector<int>> generateMatrix(int n)
{
    int x_index = 0;
    int y_index = 0;
    int width = n;
    int loop = n / 2;

    int offset = 0;
    int count = 1;
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    // n / 2 套了几个环
    while (loop--)
    {
        // 从左到右
        for (; y_index < width - 1 - offset; y_index++)
        {
            result[x_index][y_index] = count;
            count++;
        }

        // 从上到下
        for (; x_index < width - 1 - offset; x_index++)
        {
            result[x_index][y_index] = count;
            count++;
        }

        // 从右到左
        for (; y_index > 0 + offset; y_index--)
        {
            result[x_index][y_index] = count;
            count++;
        }

        // 从下到上
        for (; x_index > 0 + offset; x_index--)
        {
            result[x_index][y_index] = count;
            count++;
        }
        // 以上为一圈结束

        // 更新初始状态
        x_index++;
        y_index++;
        offset++;
    }

    // 如果n是奇数
    if (n % 2 == 1)
    {
        result[n / 2][n / 2] = n * n;
    }

    return result;
}

int main()
{
    auto result = generateMatrix(4);
    return 0;
}