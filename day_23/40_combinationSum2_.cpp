#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;

// 同层去重
void Traversal(const std::vector<int> &candidates, const int target, int sum, int start_index)
{
    // 终止条件
    if (sum == target)
    {
        result.push_back(path);
        return;
    }

    std::unordered_map<int, bool> cache; // 同层去重
    for (int i = start_index; i < candidates.size(); i++)
    {
        if (cache[candidates[i]])
            continue;
        cache[candidates[i]] = true;

        path.push_back(candidates[i]);
        sum += candidates[i];
        if (sum <= target)
            Traversal(candidates, target, sum, i + 1);
        sum -= candidates[i];
        path.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
{
    // 由于存在重复的元素，因此先进行排序，方便去重
    std::sort(candidates.begin(), candidates.end());
    Traversal(candidates, target, 0, 0);
    return result;
}

int main()
{
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    combinationSum2(candidates, target);
}
