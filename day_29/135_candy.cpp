#include <iterator>
#include <numeric>
#include <vector>

int candy(std::vector<int> &ratings)
{
    std::vector<int> res(ratings.size(), 1);

    for (int i = 0; i < ratings.size() - 1; ++i)
    {
        if ((ratings[i + 1] > ratings[i]))
        {
            res[i + 1] = res[i] + 1;
        }
    }

    for (int i = ratings.size() - 2; i >= 0; --i)
    {
        if (ratings[i] > ratings[i + 1])
        {
            res[i] = std::max(res[i + 1] + 1, res[i]);
        }
    }

    return std::accumulate(res.begin(), res.end(), 0);
}

int candyv2(std::vector<int> &ratings)
{
    std::vector<int> res(ratings.size(), 1);

    for (int i = 1; i < ratings.size(); i++) // [1, N-1]
    {
        if (ratings[i] > ratings[i - 1])
        {
            res[i] = res[i - 1] + 1;
        }
    }

    for (int i = ratings.size() - 2; i >= 0; i--) // [0, N-2]
    {
        if (ratings[i] > ratings[i + 1])
        {
            res[i] = std::max(res[i], res[i + 1] + 1);
        }
    }

    return std::accumulate(std::begin(res), std::end(res), 0);
}