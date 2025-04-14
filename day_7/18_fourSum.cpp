#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> four_sum(std::vector<int> nums, int target)
{
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        // nums 有序，
        // if nums[i] >= 0 && nums[i] > target 可以直接跳过
        if (nums[i] > target && nums[i] >= 0)
            break;

        // 去重
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < nums.size(); ++j)
        {
            // 剪枝
            if (nums[i] + nums[j] > target && nums[j] + nums[i] >= 0)
                break;

            // 去重
            if (j > j + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = nums.size() - 1;

            while (right > left)
            {

                if (nums[i] + nums[j] + nums[left] + nums[right] > target)
                {
                    right--;
                }
                else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                {
                    left++;
                }
                else
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (right < left && nums[left] == nums[left + 1])
                    {
                        left++;
                    }

                    while (right < left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        }
    }

    return result;
}

std::vector<std::vector<int>> four_sum_v2(std::vector<int> nums, int target)
{
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        if (nums[i] > target && nums[i] > 0)
            break;

        for (size_t j = i + 1; j < nums.size(); ++j)
        {
            if ((nums[j] + nums[i] > target) && (nums[j] + nums[i]) > 0)
                break;

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int l = j + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                if ((long)nums[i] + nums[j] + nums[l] + nums[r] > target)
                {
                    r--;
                }
                else if ((long)nums[i] + nums[j] + nums[l] + nums[r] < target)
                {
                    l++;
                }
                else
                {
                    result.push_back({nums[i], nums[j], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1])
                    {
                        l++;
                    }

                    while (l < r && nums[r] == nums[r - 1])
                    {
                        r--;
                    }

                    l++;
                    r--;
                }
            }
        }
    }

    return result;
}

int main()
{

    std::vector<int> nums{1, 0, -1, 0, -2, 2};

    auto res = four_sum(nums, 0);

    for (auto i : res)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}