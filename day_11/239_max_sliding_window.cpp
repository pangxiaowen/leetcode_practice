#include <queue>
#include <vector>
#include <iostream>

class MyQueue
{
private:
    std::queue<int> m_queue;

public:
    void push(int value)
    {
        // 如果value 比第一个值大，则将其取出，保证第一个值是数组中最大的
        while (!m_queue.empty() && value > m_queue.front())
        {
            m_queue.pop();
        }
        m_queue.push(value);
    }

    void pop(int value)
    {
        if (!m_queue.empty() && value == m_queue.front())
            m_queue.pop();
    }

    int front()
    {
        return m_queue.front();
    }
};

std::vector<int> max_sliding_window(std::vector<int> nums, int k)
{
    int left = 0;
    MyQueue queue;
    std::vector<int> result;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        queue.push(nums[i]);
        if (i - left == k - 1)
        {
            if (left > 0)
                queue.pop(nums[left - 1]);
            result.push_back(queue.front());
            ++left;
        }
    }

    return result;
}

int main()
{
    std::vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};

    auto res = ::max_sliding_window(nums, 3);

    for (auto it : res)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}