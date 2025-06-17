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
        if (!path.empty() && nums[i] < path.back() ||
            i > 0 && used_set.find(nums[i]) != used_set.end())
        {
            continue;
        }

        used_set.insert(nums[i]);
        path.push_back(nums[i]);
        backtracing(nums, i + 1);
        path.pop_back();
    }
}

// 确定参数以及返回值
void backtracingv2(const std::vector<int> &nums, int start_index)
{
    // 确定终止条件
    if (path.size() > 1)
    {
        // 由于求得是子序列，因此对于子节点都要放到结果中去
        result.push_back(path);
    }

    // 访问到数组的结尾进行return
    if (start_index >= nums.size())
    {
        return;
    }

    std::unordered_set<int> set;

    for (int i = start_index; i < nums.size(); i++)
    {
        // // 去重, 这种去重方法，要求数组是有序的，这里不适用，改用map/set
        // if (i > start_index && nums[i] == nums[i - 1])
        // {
        //     continue;
        // }

        // 如果path不为空且最后一个元素大于当前的元素，则跳过
        // 如果改元素使用过，则跳过
        if ((!path.empty() && path.back() > nums[i]) || (set.find(nums[i]) != set.end()))
        {
            continue;
        }

        set.insert(nums[i]);
        path.push_back(nums[i]);
        backtracingv2(nums, i + 1);
        path.pop_back();
    }
}

using namespace std;
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    backtracingv2(nums, 0);
    return result;
}

int main()
{
    std::vector<int> nums = {4, 6, 7, 7};
    findSubsequences(nums);
}