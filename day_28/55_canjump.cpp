
#include <vector>
#include <algorithm>

bool canJump(std::vector<int> nums)
{
    int cover = 0;
    if (nums.size() <= 1)
        return true;

    for (int i = 0; i < nums.size(); ++i)
    {
        cover = std::max(i + nums[i], cover);
        if (cover >= (nums.size() - 1))
        {
            return true;
        }
    }

    return false;
}