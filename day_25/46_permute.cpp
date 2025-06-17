#include <iostream>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;

void backtracking(std::vector<int> nums)
{
    if (nums.empty())
    {
        result.push_back(path);
        return;
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        std::vector<int> sub_vec = nums;
        sub_vec.erase(sub_vec.begin() + i);
        backtracking(sub_vec);
        path.pop_back();
    }
}

void backtracking_v2(std::vector<int> nums, std::vector<bool> used)
{
    if (path.size() == nums.size())
    {
        result.push_back(path);
        return;
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (used[i] == true)
            continue;
        // 同树枝进行标记,因此需要回溯
        used[i] = true;
        path.push_back(nums[i]);
        backtracking_v2(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

// 确定参数以及返回值，由于是全排列问题，我们要记录有哪些已经使用过
void backtracking_v3(const std::vector<int> &nums, std::vector<bool> &used)
{
    if (path.size() == nums.size())
    {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])
        {
            continue;
        }

        used[i] = true;
        path.push_back(nums[i]);
        backtracking_v3(nums, used);
        path.pop_back();
        used[i] = false;
    }
}
