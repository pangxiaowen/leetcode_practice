#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

static bool cmp(const std::vector<int> &a, const std::vector<int> &b) { return a[0] < b[0]; }

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    std::vector<std::vector<int>> result;
    if (intervals.size() <= 1)
        return intervals;

    std::sort(intervals.begin(), intervals.end(), cmp);

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (end >= intervals[i][0]) // 去区间重合，更新end
        {
            end = end > intervals[i][1] ? end : intervals[i][1]; // 判断end是否需要更新
        }
        else // 不重合， 保存start 和 end， 更新start end
        {
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // 保存最后一组数据
    result.push_back({start, end});

    return result;
}

vector<vector<int>> mergev2(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals;

    std::sort(intervals.begin(), intervals.end(), cmp);

    std::vector<std::vector<int>> result;

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= end) // 开始位置 小于 end, 重合，进行合并
        {
            end = std::max(intervals[i][1], end); // 更新end
        }
        else
        {
            // 不重合，记录区间，并更新start end
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    //  记录最后一组数据
    result.push_back({start, end});

    return result;
}