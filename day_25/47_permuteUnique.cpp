#include <algorithm>
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

std::vector<int> cache;
void backTracking(std::vector<int> &nums, std::vector<bool> used)
{
    if (cache.size() == nums.size())
    {
        result.push_back(cache);
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {

        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            continue;

        if (used[i] == false)
        {
            used[i] = true;
            cache.push_back(nums[i]);
            backTracking(nums, used);
            cache.pop_back();
            used[i] = false;
        }
    }
}

void backTrackingv2(std::vector<int> &nums, std::vector<bool> used)
{
    // 大小相等的时候完成了全排列，保存结果
    if (cache.size() == nums.size())
    {
        result.push_back(cache);
        return;
    }

    // 由于是全排列，因此每次都是从0开始，但是要跳过已经使用的元素
    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])
        {
            continue;
        }

        // 去重， 使用前后元素是否相等的去重方法，要求nums是排序后的
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
        {
            continue;
        }

        cache.push_back(nums[i]);
        used[i] = true;
        backTrackingv2(nums, used);
        used[i] = false;
        cache.pop_back();
    }
}

using namespace std;
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<bool> used(nums.size(), false);
    backTrackingv2(nums, used);
    return result;
}
