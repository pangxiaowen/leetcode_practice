#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;
// 去重前 要先排序
void backtracking(std::vector<int> nums, int target, int start_index)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        result.push_back(path);
    }

    std::unordered_map<int, bool> used;
    for (size_t i = start_index; i < nums.size(); ++i)
    {
        // 同层去重
        if (used[nums[i]] == true)
            continue;

        used[nums[i]] = true;

        // 剪枝
        if (target - nums[i] < 0)
            continue;

        path.push_back(nums[i]);
        backtracking(nums, target - nums[i], i + 1);
        path.pop_back();
    }
}

// 去重前 要先排序
void backtracking_v2(std::vector<int> nums, int target, int start_index)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        result.push_back(path);
    }

    for (size_t i = start_index; i < nums.size(); ++i)
    {
        // 同层去重
        if (i > start_index && nums[i] == nums[i - 1])
            continue;

        // 剪枝
        if (target - nums[i] < 0)
            continue;

        path.push_back(nums[i]);
        backtracking(nums, target - nums[i], i + 1);
        path.pop_back();
    }
}

// 理解这里used的作用，加深对回溯的理解
void backtracking_v4(std::vector<int> nums, int target, int start_index, std::vector<bool> used)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        result.push_back(path);
    }

    for (size_t i = start_index; i < nums.size(); ++i)
    {
        if (i > 0)
        {
            if (nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
        }

        // 剪枝
        if (target - nums[i] < 0)
            continue;

        path.push_back(nums[i]);
        backtracking(nums, target - nums[i], i + 1);
        path.pop_back();
    }
}