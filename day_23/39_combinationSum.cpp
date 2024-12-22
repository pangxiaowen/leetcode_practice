#include <iostream>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;

void combination_sum(std::vector<int> nums, int target, int start_index)
{
    if (target == 0)
    {
        result.push_back(path);
        return;
    }

    for (size_t i = start_index; i < nums.size(); ++i)
    {
        if (target - nums[i] < 0)
        {
            continue;
        }

        path.push_back(nums[i]);
        combination_sum(nums, target - nums[i], i);
        path.pop_back();
    }
}

void backtracking(std::vector<int> &candidates, int target, int sum, int start_index)
{
    if (sum > target)
        return;
    if (sum == target)
    {
        result.push_back(path);
    }

    for (size_t i = start_index; i < candidates.size(); ++i)
    {
        if (sum + candidates[i] > target)
            continue;
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtracking(candidates, target, sum, i);
        path.pop_back();
        sum -= candidates[i];
    }
}