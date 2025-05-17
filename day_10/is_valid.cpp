#include <iostream>
#include <stack>
#include <vector>

// 由于栈结构的特殊性，非常适合做对称匹配类的题目。
bool is_valid(std::vector<char> vec)
{
    std::stack<char> left_stack;
    std::stack<char> right_stack;

    for (auto it : vec)
    {
        left_stack.push(it);
    }

    while (!left_stack.empty())
    {
        char left_top = left_stack.top();
        left_stack.pop();

        if (left_top == '(')
        {
            if (right_stack.empty())
                return false;
            char right_top = right_stack.top();
            right_stack.pop();
            if (right_top != ')')
                return false;
        }
        else if (left_top == '[')
        {
            if (right_stack.empty())
                return false;
            char right_top = right_stack.top();
            right_stack.pop();
            if (right_top != ']')
                return false;
        }
        else if (left_top == '{')
        {
            if (right_stack.empty())
                return false;
            char right_top = right_stack.top();
            right_stack.pop();
            if (right_top != '}')
                return false;
        }
        else
        {
            right_stack.push(left_top);
        }
    }

    if (right_stack.empty())
        return true;
    else
        return false;
}

bool is_valid_v2(std::vector<char> vec)
{
    if (vec.size() % 2 != 0)
        return false;

    std::stack<int> st;
    for (auto it : vec)
    {
        if (it == '(')
        {
            st.push(')');
        }
        else if (it == '[')
        {
            st.push(']');
        }
        else if (it == '{')
        {
            st.push('}');
        }
        else if (st.empty() || it != st.top())
        {
            return false;
        }
        else
        {
            st.pop();
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    std::vector<char> vec{'(', ')', '[', ']', '{', '}'};

    std::cout << is_valid_v2(vec) << std::endl;
}