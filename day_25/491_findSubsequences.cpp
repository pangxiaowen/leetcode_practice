#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;

void backtracing(const std::vector<int> &nums, int start_index)
{
    if (path.size() >= 2)
    {
        result.push_back(path);
    }

    if (start_index > nums.size())
    {
        return;
    }

    std::unordered_set<int> used_set;
    for (size_t i = start_index; i < nums.size(); i++)
    {
        //  同层去重
        if (!path.empty() && nums[i] < path.back() || i > 0 && used_set.find(nums[i]) != used_set.end())
        {
            continue;
        }

        used_set.insert(nums[i]);
        path.push_back(nums[i]);
        backtracing(nums, i + 1);
        path.pop_back();
    }
}
