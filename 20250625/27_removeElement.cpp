#include <vector>

//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val
//的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

// 双指针法
// i 正常自加, index 只有当值不等于val的时候才增加，增加的时候将nums[i] 赋值给 nums[index]
int removeElement(std::vector<int> &nums, int val)
{
    int index = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}