#include <cstddef>
#include <iostream>
#include <queue>

class MyStack
{
public:
    MyStack() {}

    void push(int x) { m_queue.push(x); }

    int pop()
    {
        std::queue<int> m_tmp;
        while (m_queue.size() > 1)
        {
            m_tmp.push(m_queue.front());
            m_queue.pop();
        }

        int result = m_queue.front();
        m_queue = m_tmp;
        return result;
    }

    int top()
    {
        int result = pop();
        m_queue.push(result);
        return result;
    }

    bool empty() { return m_queue.empty(); }

private:
    std::queue<int> m_queue;
};

class MyStackV2
{
public:
    MyStackV2() {}

    void push(int x) { m_queue.push(x); }

    int pop()
    {
        int size = m_queue.size() - 1;
        while (size--)
        {
            m_queue.push(m_queue.front());
            m_queue.pop();
        }

        int result = m_queue.front();
        m_queue.pop();
        return result;
    }

    int top()
    {
        int result = pop();
        m_queue.push(result);
        return result;
    }

    bool empty() { return m_queue.empty(); }

private:
    std::queue<int> m_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << stack.top() << std::endl;
}
