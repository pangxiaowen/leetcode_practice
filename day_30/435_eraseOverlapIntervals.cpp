#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

static bool cmp(const std::vector<int> &a, const std::vector<int> &b)
{
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return 0;

    std::sort(intervals.begin(), intervals.end(), cmp);

    int count = 0;
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] < end)
        {
            count++;
        }
        else
        {
            end = intervals[i][1];
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "需要移除的最小区间数量: " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}