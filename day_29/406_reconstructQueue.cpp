#include <algorithm>
#include <numeric>
#include <vector>

static bool cmp(const std::vector<int> &a, const std::vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people)
{
    std::sort(people.begin(), people.end(), cmp);

    std::vector<std::vector<int>> res;

    for (int i = 0; i < people.size(); ++i)
    {
        res.insert(res.begin() + people[i][1], people[i]);
    }

    return res;
}

int main()
{
}