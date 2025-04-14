#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int four_sum_count(std::vector<int> A, std::vector<int> B, std::vector<int> C, std::vector<int> D)
{
    std::unordered_map<int, int> a_b_sum;

    for (auto a : A)
    {
        for (auto b : B)
        {
            a_b_sum[a + b]++;
        }
    }

    int count = 0;
    for (auto c : C)
    {
        for (auto d : D)
        {
            int tmp = 0 - c - d;
            auto iter = a_b_sum.find(tmp);
            if (iter != a_b_sum.end())
            {
                count += iter->second;
            }
        }
    }

    return count;
}

int four_sum_count_v2(std::vector<int> A, std::vector<int> B, std::vector<int> C,
                      std::vector<int> D)
{
    std::unordered_map<int, int> ab_sum;
    std::unordered_map<int, int> cd_sum;

    for (const auto &a : A)
    {
        for (const auto &b : B)
        {
            ab_sum[a + b]++;
        }
    }

    for (const auto &c : C)
    {
        for (const auto &d : D)
        {
            cd_sum[c + d]++;
        }
    }

    int count = 0;
    for (auto &ab : ab_sum)
    {
        int dist = 0 - ab.first;

        auto it = cd_sum.find(dist);
        if (it != cd_sum.end())
        {
            count += ab.second * it->second;
        }
    }

    return count;
}

int main()
{
    std::vector<int> A{1, 2};
    std::vector<int> B{-2, -1};
    std::vector<int> C{-1, 2};
    std::vector<int> D{0, 2};

    std::cout << four_sum_count(A, B, C, D) << std::endl;
}