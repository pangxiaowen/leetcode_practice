#include <iostream>
#include <vector>

std::vector<std::vector<std::string>> result;
std::vector<std::string> path;

bool is_palindrome(const std::string &s, int start, int end)
{
    // 当 start == end 的时候直接不进行for循环，返回true
    for (size_t i = start, j = end; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }

    return true;
}

void backtring(std::string str, int start_index)
{
    if (start_index >= str.size())
    {
        result.push_back(path);
        return;
    }

    if (str.empty())
        return;

    for (size_t i = start_index; i < str.size(); ++i)
    {
        // 判断str是否是回文
        if (is_palindrome(str, start_index, i))
        {
            std::string s = s.substr(start_index, i - start_index + 1);
            path.push_back(s);
        }
        else
        {
            continue;
        }

        backtring(str, i + 1);
        path.pop_back();
    }
}

int main()
{

    std::string s = "aab";

    backtring(s, 0);

    return 0;
}