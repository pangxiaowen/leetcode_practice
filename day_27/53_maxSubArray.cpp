#include <string>
#include <vector>

using namespace std;
int maxSubArray(vector<int> &nums)
{
    int result = INT32_MIN;
    int count = 0;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        count = count + nums[i];

        if (count > result)
            result = count;

        if (count < 0)
        {
            count = 0;
        }
    }

    return result;
}

int maxSubArray_v2(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];

    int result;
    for (size_t i = 1; i < nums.size(); ++i)
    {
        dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
        if (dp[i] > result)
            result = dp[i];
    }

    return result;
}

int maxSubArray_v3(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int left = 0;
    int count = nums[0];
    int result = count;

    for (int i = 1; i < nums.size(); i++)
    {
        while (count < 0 && left < i)
        {
            count -= nums[left];
            left++;
        }

        count += nums[i];
        result = std::max(result, count);
    }

    return result;
}