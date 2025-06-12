
#include <algorithm>
#include <vector>

bool canJump(std::vector<int> nums)
{

    if (nums.size() <= 1)
        return 0;

    int step = 0;
    int cur_cover = 0;
    int next_cover = 0;

    // 在当前的覆盖区间内，找到最大的下一个覆盖区间。
    for (int i = 0; i < nums.size(); i++)
    {
        next_cover = std::max(i + nums[i], next_cover);

        if (i == cur_cover) // 当前区间访问结束，进行一次跳跃，跳跃到下一个覆盖区间。
        {
            step++;
            cur_cover = next_cover;
            if (cur_cover >= (nums.size() - 1))
            {
                break;
            }
        }
    }

    return step;
}