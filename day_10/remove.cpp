#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

std::string remove(std::string str)
{
    std::stack<char> st;

    for (auto it : str)
    {
        if (st.empty())
        {
            st.push(it);
        }
        else
        {
            if (st.top() == it)
            {
                st.pop();
            }
            else
            {
                st.push(it);
            }
        }
    }

    std::string result = "";
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string remove_v2(std::string str)
{
    std::string res;

    for (auto it : str)
    {
        if (res.empty() || res.back() != it)
        {
            res.push_back(it);
        }
        else
        {
            res.pop_back();
        }
    }

    return res;
}

int main()
{
    std::string str = "abbaca";
    std::cout << remove_v2(str) << std::endl;
    return 0;
}