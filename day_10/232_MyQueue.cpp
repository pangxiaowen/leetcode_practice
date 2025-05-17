#include <stack>

class MyQueue
{
public:
    MyQueue() {}

    void push(int x) { m_in_stack.push(x); }

    int pop()
    {
        if (m_out_stack.empty())
        {
            while (!m_in_stack.empty())
            {
                auto it = m_in_stack.top();
                m_out_stack.push(it);
                m_in_stack.pop();
            }
        }

        int result = m_out_stack.top();
        m_out_stack.pop();
        return result;
    }

    int peek()
    {
        if (m_out_stack.empty())
        {
            while (!m_in_stack.empty())
            {
                auto it = m_in_stack.top();
                m_out_stack.push(it);
                m_in_stack.pop();
            }
        }

        return m_out_stack.top();
    }

    bool empty() { return m_in_stack.empty() && m_out_stack.empty(); }

private:
    std::stack<int> m_in_stack;
    std::stack<int> m_out_stack;
};