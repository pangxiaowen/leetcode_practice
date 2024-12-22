#include <iostream>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> sub_set;

void backtracking(std::vector<int> nums, int start_index, std::vector<bool> used)
{
    result.push_back(sub_set);
    if (start_index >= nums.size())
    {
        return;
    }

    for (size_t i = start_index; i < nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
        {
            continue;
        }

        sub_set.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, i + 1, used);
        used[i] = false;
        sub_set.pop_back();
    }
}