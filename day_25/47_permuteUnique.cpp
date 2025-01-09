#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;

void backtracking(std::vector<int> nums, std::vector<bool> used)
{
    if (path.size() == nums.size())
    {
        result.push_back(path);
    }

    std::unordered_set<int> cache;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (used[i] == true)
            continue;
        if (i > 0 && cache.find(nums[i]) != cache.end())
            continue;

        used[i] = true;
        path.push_back(nums[i]);
        cache.insert(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
    }
}