#include <vector>

// 给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
int rangSum(const std::vector<int> vec, int start, int end)
{
    int result = 0;
    for (int i = start; i < end; i++)
    {
        result += vec[i];
    }
    return result;
}

int rangSumv2(std::vector<int> vec, int start, int end)
{
    // 累计求和

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            vec[i] = vec[i] + vec[j];
        }
    }

    return vec[end - 1] - vec[start];
}