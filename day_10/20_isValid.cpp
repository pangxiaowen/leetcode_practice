#include <cstddef>
#include <stack>
#include <string>

bool isValid(std::string s)
{
    std::stack<char> st;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] == ')')
        {
            if (st.empty())
                return false;

            auto it = st.top();
            if (it != '(')
            {
                return false;
            }
            st.pop();
            continue;
        }

        if (s[i] == ']')
        {
            if (st.empty())
                return false;
            auto it = st.top();
            if (it != '[')
            {
                return false;
            }
            st.pop();
            continue;
        }

        if (s[i] == '}')
        {
            if (st.empty())
                return false;
            auto it = st.top();
            if (it != '{')
            {
                return false;
            }
            st.pop();
            continue;
        }

        st.push(s[i]);
    }

    if (!st.empty())
        return false;
    return true;
}
