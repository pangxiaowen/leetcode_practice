#include <iostream>
#include <stack>
#include <vector>

class MyQueue
{
  private:
    std::stack<int> m_in_stack;
    std::stack<int> m_out_stack;

  public:
    MyQueue() {};

    bool empty()
    {
        // 输入输出都是空, 则队列是空
        return m_in_stack.empty() && m_out_stack.empty();
    }

    void pop()
    {
        if (m_out_stack.empty())
        {
            //  如果输出栈是空,则将输入栈全部放入输出栈
            while (!m_in_stack.empty())
            {
                m_out_stack.push(m_in_stack.top());
                m_in_stack.pop();
            }
        }
        m_out_stack.pop();
    }

    int peek()
    {
        if (m_out_stack.empty())
        {
            //  如果输出栈是空,则将输入栈全部放入输出栈
            while (!m_in_stack.empty())
            {
                m_out_stack.push(m_in_stack.top());
                m_in_stack.pop();
            }
        }

        return m_out_stack.top();
    }

    void push(int i)
    {
        m_in_stack.push(i);
    }
};

int main()
{
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << queue.peek() << std::endl;
}
