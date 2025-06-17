#include <iostream>
#include <vector>

std::vector<std::vector<int>> result;
void tracebacking(int n, int k, int start_index, std::vector<int> vec)
{
    if (k == vec.size())
    {
        result.push_back(vec);
        return;
    }

    for (size_t i = start_index; i <= n - (k - vec.size()) + 1; i++)
    {
        vec.push_back(i);
        tracebacking(n, k, i + 1, vec);
        vec.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<int> vec;
    tracebacking(n, k, 1, vec);
    return result;
}

void traceBacking(int n, int k, int start, std::vector<int> res)
{
    if (k == res.size())
    {
        result.push_back(res);
        return;
    }

    for (int i = start; i <= (n - (k - res.size()) + 1); i++)
    {
        res.push_back(i);
        traceBacking(n, k, i + 1, res);
        res.pop_back();
    }
}

int main()
{
    auto res = combine(4, 4);

    for (auto it : res)
    {
        for (auto i : it)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}