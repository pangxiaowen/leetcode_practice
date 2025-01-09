#include <vector>

int maxProfit(std::vector<int> vals)
{
    int result = 0;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        int val = vals[i] - vals[i - 1];
        if (val > 0)
        {
            result += val;
        }
    }

    return result;
}