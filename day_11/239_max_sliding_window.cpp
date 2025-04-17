#include <cstddef>
#include <cstdint>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

class Mydeque
{
private:
    // 双向队列
    std::deque<int> m_deque;

public:
    void push(int value)
    {
        // 如果push的值比最后一个值大，则将最后一个值出队，直到deque有序为止
        while (!m_deque.empty() && value > m_deque.back())
        {
            m_deque.pop_back();
        }
        m_deque.push_back(value);
    }

    void pop(int value)
    {
        // 如果deque的第一个值，是需要pop的值，则将其pop出去，否则则不做操作
        if (!m_deque.empty() && value == m_deque.front())
            m_deque.pop_front();
    }

    int front() { return m_deque.front(); }
};

std::vector<int> max_sliding_window(std::vector<int> nums, int k)
{
    int left = 0;
    Mydeque deque;
    std::vector<int> result;

    for (size_t i = 0; i < k; ++i)
    {
        deque.push(nums[i]);
    }
    result.push_back(deque.front());

    for (size_t i = k; i < nums.size(); ++i)
    {
        deque.pop(nums[i - k]);
        deque.push(nums[i]);
        result.push_back(deque.front());
    }

    return result;
}

int getMax(std::queue<int> que)
{
    int max = INT32_MIN;
    int size = que.size();
    for (size_t i = 0; i < size; ++i)
    {
        if (max < que.front())
        {
            max = que.front();
        }
        que.pop();
    }
    return max;
}

std::vector<int> max_sliding_windowV2(std::vector<int> nums, int k)
{
    std::queue<int> que;
    std::vector<int> result;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (que.size() < k)
        {
            que.push(nums[i]);
        }
        else
        {
            que.pop();
            que.push(nums[i]);
            result.push_back(getMax(que));
        }
    }

    if (que.size() == k)
        result.push_back(getMax(que));

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