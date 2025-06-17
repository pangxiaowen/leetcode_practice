#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;

void backTracking(const std::vector<int> &candidates, const int &target, int sum, int start_index)
{
    if (sum == target)
    {
        result.push_back(path);
        return;
    }

    for (int i = start_index; i < candidates.size(); i++)
    {
        path.push_back(candidates[i]);
        sum += candidates[i];
        if (sum <= target)
            backTracking(candidates, target, sum, i);
        sum -= candidates[i];
        path.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    backTracking(candidates, target, 0, 0);
    return result;
}