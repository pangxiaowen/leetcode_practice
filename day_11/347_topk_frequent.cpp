#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

class mycomparison
{
public:
    bool operator()(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
    {
        return lhs.second > rhs.second;
    }
};

std::vector<int> topk_frequent(std::vector<int> nums, int k)
{
    std::unordered_map<int, int> nums_map;

    for (auto it : nums)
    {
        nums_map[it]++;
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, mycomparison> prio_queue;

    for (auto it : nums_map)
    {
        prio_queue.push(it);
        if (prio_queue.size() > k)
            prio_queue.pop();
    }

    std::vector<int> result(k);
    for (int i = k - 1; i >= 0; i--)
    {
        result[i] = prio_queue.top().first;
        prio_queue.pop();
    }

    return result;
}

int main()
{
    std::vector<int> nums{1, 1, 1, 2, 2, 3};

    auto res = topk_frequent(nums, 3);

    for (auto it : res)
    {
        std::cout << it << " ";
    }

    std::cout << std::endl;
    return 0;
}