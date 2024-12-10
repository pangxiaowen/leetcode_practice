#include <iostream>
#include <queue>

class MyStack
{
  private:
    std::queue<int> m_queue;
    std::queue<int> m_queue_back;

  public:
    void push(int x)
    {
        m_queue.push(x);
    }

    void pop()
    {
        if (m_queue.empty())
            return;

        // 只保留最后一个
        while (m_queue.size() != 1)
        {
            m_queue_back.push(m_queue.front());
            m_queue.pop();
        }

        m_queue.pop();
        m_queue = m_queue_back;

        while (!m_queue_back.empty())
        {
            m_queue_back.pop();
        }
    }

    int top()
    {
        if (m_queue.empty())
            return -1;

        // 只保留最后一个
        while (m_queue.size() != 1)
        {
            m_queue_back.push(m_queue.front());
            m_queue.pop();
        }

        int result = m_queue.front();

        m_queue = m_queue_back;
        m_queue.push(result);

        while (!m_queue_back.empty())
        {
            m_queue_back.pop();
        }

        return result;
    }

    bool empty()
    {
        return m_queue.empty();
    }
};

class MystackV2
{
  private:
    std::queue<int> m_queue;

  public:
    void push(int x)
    {
        m_queue.push(x);
    }

    void pop()
    {
        size_t size = m_queue.size();
        for (size_t i = m_queue.size(); i > 1; --i)
        {
            m_queue.push(m_queue.front());
            m_queue.pop();
        }

        m_queue.pop();
    }

    int top()
    {
        size_t size = m_queue.size();
        for (size_t i = m_queue.size(); i > 1; --i)
        {
            m_queue.push(m_queue.front());
            m_queue.pop();
        }

        int result = m_queue.front();

        m_queue.push(result);
        m_queue.pop();

        return result;
    }

    bool empty()
    {
        return m_queue.empty();
    }
};

int main()
{
    MystackV2 stack;
    stack.push(1);
    stack.push(2);

    std::cout << stack.top() << std::endl;
    stack.pop();
    std::cout << stack.top() << std::endl;
    stack.pop();

    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout << stack.top() << std::endl;
    stack.pop();
    std::cout << stack.top() << std::endl;
}
