#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> result;
void tracebacking(int n, int k, int j, int start_index, std::vector<int> vec, int sum)
{
    if (sum == n && vec.size() == k)
    {
        result.push_back(vec);
        return;
    }

    for (size_t i = start_index; i <= j - (k - vec.size()) + 1; i++)
    {
        vec.push_back(i);
        sum += i;
        if (sum <= n)
            tracebacking(n, k, j, i + 1, vec, sum);
        sum -= i;
        vec.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<int> vec;
    tracebacking(n, k, 9, 1, vec, 0);
    return result;
}

int main()
{
    auto res = combine(9, 3);

    for (auto it : res)
    {
        for (auto i : it)
        {
            std::cout << i << " ";
        }
        std::cout << "#######" << std::endl;
    }

    return 0;
}