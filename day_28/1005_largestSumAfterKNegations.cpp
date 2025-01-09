#include <vector>
#include <algorithm>
#include <numeric>

static bool cmp(int a, int b)
{
    return abs(a) > abs(b);
}

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