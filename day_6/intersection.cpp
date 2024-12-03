#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int> a, std::vector<int> b)
{
    std::unordered_set<int> tmp;
    std::vector<int> res;
    for (auto it : a)
    {
        tmp.insert(it);
    }

    for (auto it : b)
    {
        auto iter = tmp.find(it);
        if (iter != tmp.end())
        {
            res.push_back(it);
            tmp.erase(iter);
        }
    }

    return res;
}

std::vector<int> intersection_v2(std::vector<int> a, std::vector<int> b)
{
    std::unordered_set<int> result_set;
    std::unordered_set<int> nums_set{a.begin(), a.end()};
    for (auto num : b)
    {
        if (nums_set.find(num) != nums_set.end())
        {
            result_set.insert(num);
        }
    }

    return std::vector<int>{result_set.begin(), result_set.end()};
}

int main()
{
    std::vector<int> a{1, 2, 2, 1};
    std::vector<int> b{2, 2};

    auto res = intersection_v2(a, b);

    for (auto it : res)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}