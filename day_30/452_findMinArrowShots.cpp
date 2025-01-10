#include <vector>
#include <algorithm>

using namespace std;
static bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

int findMinArrowShots(vector<vector<int>> &points)
{
    std::sort(points.begin(), points.end(), cmp);

    if (points.empty())
        return 0;

    int count = 1;
    for (int i = 1; i < points.size(); i++)
    {
        // 未相交
        if (points[i][0] > points[i - 1][1])
        {
            count++;
        }
        else // 考虑相交以及内含两种情况
        {
            points[i][1] = std::min(points[i - 1][1], points[i][1]);
        }
    }

    return 0;
}
