#include <algorithm>
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

// 理解这里used的作用，加深对回溯的理解
void backtracking_v2(const std::vector<int> &nums, const int &target, int sum, int start_index,
                     std::vector<bool> &used)
{
    if (sum == target)
    {
        result.push_back(path);
        return;
    }

    for (int i = start_index; i < nums.size(); i++)
    {
        if (i > 0 && (nums[i] == nums[i - 1]) && used[i - 1] == false)
        {
            continue;
        }

        sum += nums[i];
        path.push_back(nums[i]);
        used[i] = true;
        backtracking_v2(nums, target, sum, i + 1, used);
        used[i] = false;
        path.pop_back();
        sum -= nums[i];
    }
}

using namespace std;
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    std::vector<bool> used(candidates.size(), false);
    backtracking_v2(candidates, target, 0, 0, used);
    return result;
}

int main()
{
    std::vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    combinationSum2(nums, target);
}