#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

std::vector<std::vector<int>> three_sum(std::vector<int> nums)
{
    std::vector<std::vector<int>> result;

    // 对数组进行排序
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > 0) // 数组是有序的，若第一个数大于0, 则直接break
            break;

        int dist = 0 - nums[i]; // 在剩下的数组中寻找 b + c = dist

        std::unordered_map<int, int> tmp_map;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            int dist_b_c = dist - nums[j];
            auto iter = tmp_map.find(dist_b_c);
            if (iter != tmp_map.end())
            {
                result.push_back({nums[i], nums[j], nums[iter->second]});
            }
            else
            {
                tmp_map.insert({nums[j], j});
            }
        }
    }

    return result;
}

std::vector<std::vector<int>> three_sum_v2(std::vector<int> nums)
{
    std::vector<std::vector<int>> result;

    // 对数组进行排序
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > 0) // 数组是有序的，若第一个数大于0, 则直接break
            break;

        if (i > 0 && nums[i] == nums[i - 1]) // 对a进行去重
            continue;

        std::unordered_set<int> set;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            // 对b进行去重
            if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                continue;

            int c = 0 - (nums[i] + nums[j]);
            if (set.find(c) != set.end())
            {
                result.push_back({nums[i], nums[j], c});
                set.erase(c);
            }
            else
            {
                set.insert(nums[j]);
            }
        }
    }

    return result;
}

std::vector<std::vector<int>> three_sum_v3(std::vector<int> nums)
{
    std::vector<std::vector<int>> result;

    // 对数组进行排序
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > 0)
            return result;

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (right > left)
        {
            if (nums[i] + nums[left] + nums[right] > 0)
            {
                right--;
            }
            else if (nums[i] + nums[left] + nums[right] < 0)
            {
                left++;
            }
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});

                while (right > left && nums[right] == nums[right - 1])
                {
                    right--;
                }

                while (right > left && nums[left] == nums[left + 1])
                {
                    left++;
                }

                right--;
                left++;
            }
        }
    }

    return result;
}

int main()
{
    std::vector<int> nums{-2, -1, 0, 0, 0, 1, 1, 1, 2};

    auto res = three_sum_v3(nums);

    for (auto i : res)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}