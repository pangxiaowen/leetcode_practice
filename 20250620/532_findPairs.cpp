#include <algorithm>
#include <vector>

int findPairs(std::vector<int> &nums, int k)
{
    std::sort(nums.begin(), nums.end());

    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j - 1] == nums[j])
            {
                continue;
            }

            if (nums[j] - nums[i] == k)
            {
                result++;
            }
        }
    }

    return result;
}

int findPairsv2(std::vector<int> &nums, int k) { std::sort(nums.begin(), nums.end()); }

int main()
{
    std::vector<int> vec{1, 2, 4, 4, 3, 3, 0, 9, 2, 3};
    findPairs(vec, 3);
    return 0;
}