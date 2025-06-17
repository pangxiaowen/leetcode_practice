#include <iostream>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> sub_set;

void backtracking(std::vector<int> nums, int start_index)
{
    result.push_back(sub_set);
    if (start_index >= nums.size())
    {
        return;
    }

    for (size_t i = start_index; i < nums.size(); ++i)
    {
        sub_set.push_back(nums[i]);
        backtracking(nums, i + 1);
        sub_set.pop_back();
    }
}

namespace pxw
{
std::vector<std::vector<int>> result;
std::vector<int> sub_set;

void backtracking(std::vector<int> nums, int start_index)
{
    result.push_back(sub_set);

    if (start_index >= nums.size())
    {
        return;
    }

    for (int i = start_index; i < nums.size(); i++)
    {
        sub_set.push_back(nums[i]);
        backtracking(nums, i + 1);
        sub_set.pop_back();
    }
}
} // namespace pxw