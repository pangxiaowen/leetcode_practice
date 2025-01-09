#include <algorithm>
#include <vector>

using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    int res = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 0; j < g.size(); j++)
        {
            if (s[i] >= g[j])
            {
                g.erase(g.begin() + j);
                res++;
                break;
            }
            else
            {
                break;
            }
        }
    }

    return res;
}

int findContentChildren_v2(vector<int> &g, vector<int> &s)
{
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    int res = 0;

    int index = s.size() - 1;
    for (size_t i = g.size(); i >= 0; i--)
    {
        if (index > 0 && g[i] < s[index])
        {
            index--;
            res++;
        }
    }

    return res;
}