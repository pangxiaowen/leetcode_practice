#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> two_sum(std::vector<int> nums, int target)
{
    std::unordered_set<int> nums_set{nums.begin(), nums.end()};

    for (auto it : nums)
    {
        int dist = target - it;
        if (nums_set.find(dist) != nums_set.end())
        {
            auto iter_a = std::find(nums.begin(), nums.end(), dist);
            auto iter_b = std::find(nums.begin(), nums.end(), it);

            int index_a = iter_a - nums.begin();
            int index_b = iter_b - nums.begin();

            return std::vector<int>{index_a, index_b};
        }
    }

    return std::vector<int>{};
}

std::vector<int> two_sum_v2(std::vector<int> nums, int target)
{
    std::unordered_map<int, int> nums_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int key = nums[i];
        int val = i;

        nums_map.insert({key, val});
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int dist = target - nums[i];
        auto res_iter = nums_map.find(dist);

        if (res_iter != nums_map.end())
        {
            return std::vector<int>{i, res_iter->second};
        }
    }

    return std::vector<int>{};
}

std::vector<int> two_sum_v3(std::vector<int> nums, int target)
{
    std::unordered_map<int, int> nums_map;

    for (int i = 0; i < nums.size(); i++)
    {
        int dist = target - nums[i];
        auto res_iter = nums_map.find(dist);

        if (res_iter != nums_map.end())
        {
            return std::vector<int>{i, res_iter->second};
        }
        else
        {
            nums_map.insert({nums[i], i});
        }
    }

    return std::vector<int>{};
}

int main()
{
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;

    auto res = two_sum_v3(nums, target);

    for (auto it : res)
    {
        std::cout << it << " ";
    }

    std::cout << std::endl;
    return 0;
}