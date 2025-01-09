#include <memory>
#include <string>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums.size();

    int prediff = 0;
    int curdiff = 0;
    int res = 1;

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        curdiff = nums[i + 1] - nums[i];
        if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0))
        {
            res++;
            prediff = curdiff;
        }
    }
    return res;
}

int wiggleMaxLength_v2(vector<int> &nums)
{
    int dp[1005][2];

    if (nums.size() <= 1)
        return nums.size();

    int prediff = 0;
    int curdiff = 0;
    int res = 1;

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        curdiff = nums[i + 1] - nums[i];
        if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0))
        {
            res++;
            prediff = curdiff;
        }
    }
    return res;
}