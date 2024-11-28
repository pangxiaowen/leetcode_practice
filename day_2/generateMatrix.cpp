#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate_martix(int n)
{
    std::vector<std::vector<int>> res(n, std::vector<int>(n, 0)); // 定义一个二维数组
    int startx = 0, starty = 0;                                   // 定义每循环一圈的起始位置
    int loop = n / 2; // 每圈循环几次，例如n为奇数3，那么loop=1,只循环一圈
    int mid = n / 2;  // 矩阵中间的位置, 例如： n=3, 中间位置就是(1, 1)
    int count = 1;    // 用来给矩阵中每一个空格赋值
    int offset = 1;   // 需要控制每一条遍历的长度, 每次循环右边界收缩一位
    int i, j;

    while (loop--)
    {
        i = startx;
        j = starty;

        // 上行从左到右边
        for (j; j < n - offset; j++)
        {
            res[i][j] = count++;
        }

        // 右列从上到下
        for (i; i < n - offset; i++)
        {
            res[i][j] = count++;
        }

        // 下行从右到左
        for (j; j > startx; j--)
        {
            res[i][j] = count++;
        }

        // 左列从下到上
        for (i; i > starty; i--)
        {
            res[i][j] = count++;
        }

        startx++;
        starty++;
        offset++;
    }

    if (n % 2)
    {
        res[mid][mid] = count;
    }

    return res;
}

std::vector<std::vector<int>> generate_martix_v2(int n)
{
    std::vector<std::vector<int>> res(n, std::vector<int>(n, 0)); // 定义一个二维数组
    int loop = n / 2; // 循环多少圈, 若n为奇数, 3 则loop 1圈, 中间有一个空格, 需要最后填补一下。
    int startx = 0; // 每一圈的起始位置
    int starty = 0;
    int count = 0;
    int offset = 0; // 每运行一圈，下一圈行列要进行收缩

    // 左开右闭
    while (loop--)
    {
        // i 行 j列
        int i = startx;
        int j = starty;
        // 上行从左到右
        for (j; j < n - offset - 1; j++)
        {
            res[i][j] = count++;
        }

        // 右列从上到下
        for (i; i < n - offset - 1; i++)
        {
            res[i][j] = count++;
        }

        // 下行从右到左
        for (j; j > startx; j--)
        {
            res[i][j] = count++;
        }

        // 左列从下到上
        for (i; i > starty; i--)
        {
            res[i][j] = count++;
        }

        startx++;
        starty++;
        offset++;
    }

    if (n % 2)
    {
        int mid = n % 2;
        res[mid][mid] = count;
    }

    return res;
}

int main()
{
    auto res = generate_martix_v2(10);

    for (auto vec : res)
    {
        for (auto it : vec)
            std::cout << it << " ";
        std::cout << std::endl;
    }

    return 0;
}