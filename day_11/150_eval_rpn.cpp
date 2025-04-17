#include <iostream>
#include <stack>
#include <string>
#include <vector>

int eval_rpn(std::vector<char> vec)
{
    std::stack<int> st;

    for (auto it : vec)
    {
        if (it == '+')
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            int res = left + right;
            st.push(res);
        }
        else if (it == '-')
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            int res = left - right;
            st.push(res);
        }
        else if (it == '*')
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            int res = left * right;
            st.push(res);
        }
        else if (it == '/')
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            if (right == 0)
                return -1;
            int res = left / right;
            st.push(res);
        }
        else
        {
            st.push(static_cast<int>(it) - static_cast<int>('0'));
        }
    }

    return st.top();
}

int evalRPN(std::vector<std ::string> &tokens)
{
    std::stack<int> st;
    for (const auto &it : tokens)
    {
        if (it == "+")
        {
            int l, r;
            r = st.top();
            st.pop();
            l = st.top();
            st.pop();
            st.push(l + r);
        }
        else if (it == "-")
        {
            int l, r;
            r = st.top();
            st.pop();
            l = st.top();
            st.pop();
            st.push(l - r);
        }
        else if (it == "*")
        {
            int l, r;
            r = st.top();
            st.pop();
            l = st.top();
            st.pop();
            st.push(l * r);
        }
        else if (it == "/")
        {
            int l, r;
            r = st.top();
            st.pop();
            l = st.top();
            st.pop();
            st.push(l / r);
        }
        else
        {
            st.push(std::stoi(it));
        }
    }

    return st.top();
}

int main()
{
    std::vector<char> vec{'2', '1', '+', '3', '*'};
    std::cout << eval_rpn(vec) << std::endl;

    return 0;
}