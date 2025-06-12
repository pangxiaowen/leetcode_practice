#include <algorithm>
#include <numeric>
#include <vector>

static bool cmp(int a, int b) { return abs(a) > abs(b); }

int largestSumAfterKNegations(std::vector<int> nums, int k)
{
    int result;
    std::sort(nums.begin(), nums.end(), cmp);

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] < 0)
        {
            nums[i] = -nums[i];
            k--;
        }
    }

    if (k % 2 == 1)
        nums[nums.size() - 1] *= -1;

    std::accumulate(nums.begin(), nums.end(), 0);
    return result;
}

int largestSumAfterKNegationsv2(std::vector<int> nums, int k)
{
    // 从小到大排序
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < k; i++)
    {
        nums[0] = -nums[0];
        std::sort(nums.begin(), nums.end());
    }

    return std::accumulate(nums.begin(), nums.end(), 0);
}