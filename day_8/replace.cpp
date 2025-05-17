#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

int cal_nums(std::string str)
{
    int count = 0;
    for (auto it : str)
    {
        if (it >= 'a' && it <= 'z')
        {
            continue;
        }

        count++;
    }

    return count;
}

std::string replace(std::string str)
{
    int count = cal_nums(str);
    std::string new_str;
    new_str.resize(str.size() + count * 5);

    int first = str.size() - 1;
    int last = new_str.size() - 1;

    std::string insert_str = "number";

    for (int i = first; i >= 0; i--)
    {
        // 如果是字母
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            new_str[last] = str[i];
            last--;
        }
        else
        {
            int end = insert_str.size() - 1;
            for (int j = end; j >= 0; j--)
            {
                new_str[last] = insert_str[j];
                last--;
            }
        }
    }

    return new_str;
}

std::string replace_v2(std::string str)
{
    std::string insert = "number";
    std::stringstream ss;

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] < 'a')
        {
            ss << insert;
        }
        else
        {
            ss << str[i];
        }
    }

    return ss.str();
}

int main()
{
    std::string str = "a1b2bc";
    std::cout << replace_v2(str) << std::endl;
}