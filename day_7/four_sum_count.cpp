#include <vector>
#include <iostream>
#include <unordered_map>

int four_sum_count(std::vector<int> A,
                   std::vector<int> B,
                   std::vector<int> C,
                   std::vector<int> D)
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

int main()
{
    std::vector<int> A{1, 2};
    std::vector<int> B{-2, -1};
    std::vector<int> C{-1, 2};
    std::vector<int> D{0, 2};

    std::cout << four_sum_count(A, B, C, D) << std::endl;
}