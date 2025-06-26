#include <algorithm>
#include <vector>

// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序
// 排序。

std::vector<int> sortedSquares(std::vector<int> &nums)
{
    std::vector<int> vec;
    for (int i = 0; i < nums.size(); ++i)
    {
        vec.push_back(nums[i] * nums[i]);
    }

    std::sort(vec.begin(), vec.end());
    return vec;
}

// [-4,-1,0,3,10]
// 采用双值法
// 最大值只会出现在两侧
// i --> start  j--> end
// 如果 j 的平方更大，将结果保存, 然后j--
// 如果 i 的平方更大，将结果保存, 然后i++
std::vector<int> sortedSquaresv2(std::vector<int> &nums)
{
    int k = nums.size() - 1;
    std::vector<int> result(nums.size(), 0);
    for (int i = 0, j = nums.size() - 1; i <= j;)
    {
        if (nums[i] * nums[i] > nums[j] * nums[j])
        {
            result[k] = nums[i] * nums[i];
            i++;
        }
        else
        {
            result[k] = nums[j] * nums[j];
            j--;
        }
        k--;
    }

    return result;
}

int main()
{
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    sortedSquaresv2(nums);
}