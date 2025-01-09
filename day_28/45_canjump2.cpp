
#include <vector>
#include <algorithm>

bool canJump(std::vector<int> nums)
{
    int cover = 0;
    if (nums.size() <= 1)
        return true;

    int step = 0;
    int curr_cover = 0;
    int next_cover = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        next_cover = std::max(nums[i] + i, next_cover);
        if (i == curr_cover)
        {
            step++;
            curr_cover = next_cover;
            if (next_cover >= nums.size() - 1)
                break;
        }
    }

    return false;
}