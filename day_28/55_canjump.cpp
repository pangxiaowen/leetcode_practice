
#include <algorithm>
#include <vector>

bool canJump(std::vector<int> nums)
{
    int cover = 0;
    if (nums.size() <= 1)
        return true;

    for (int i = 0; i < cover; ++i) // i只能在cover的范围内移动
    {
        cover = std::max(i + nums[i], cover);
        if (cover >= (nums.size() - 1))
        {
            return true;
        }
    }

    return false;
}

bool canJumpv2(std::vector<int> nums)
{
    int cover = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i <= cover)                           // 保证i在覆盖的范围内
            cover = std::max(i + nums[i], cover); // 是否扩大覆盖范围
    }

    if (cover >= (nums.size() - 1))
    {
        return true;
    }

    return false;
}