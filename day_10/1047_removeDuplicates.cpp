#include <algorithm>
#include <cstddef>
#include <sstream>
#include <stack>
#include <string>

std::string removeDuplicates(std::string s)
{
    std::stack<char> st;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!st.empty() && s[i] == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    std::stringstream ss;
    while (!st.empty())
    {
        ss << st.top();
        st.pop();
    }

    std::string result = ss.str();
    std::reverse(result.begin(), result.end());
    return result;
}

std::string removeDuplicatesV2(std::string s)
{
    std::string result;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (result.empty() || result.back() != s[i])
        {
            result.push_back(s[i]);
        }
        else
        {
            result.pop_back();
        }
    }

    return result;
}
