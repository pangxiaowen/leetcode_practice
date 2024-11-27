#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

void sort(std::vector<int> &vec)
{
    for (auto &it : vec)
    {
        it = it * it;
    }

    std::sort(vec.begin(), vec.end());
}

void sort_v2(std::vector<int> &vec)
{
    int l = 0;
    int r = vec.size() - 1;

    std::vector<int> res;
    res.resize(vec.size());

    for (size_t i = r; i > 0; i--)
    {
        if (vec[l] * vec[l] < vec[r] * vec[r])
        {
            res[i] = vec[r] * vec[r];
            r--;
        }
        else
        {
            res[i] = vec[l] * vec[l];
            l++;
        }
    }

    vec = res;
}

int main()
{
    std::vector<int> vec{-4, -1, 0, 3, 10};

    // sort(vec);
    sort_v2(vec);

    for (auto it : vec)
    {
        std::cout << it << " ";
    }
    return 0;
}