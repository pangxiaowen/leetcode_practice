#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle)
{
    int index = -1;
    if (haystack.size() < needle.size())
        return index;

    for (size_t i = 0; i < haystack.size(); ++i)
    {
        bool is_equal = true;
        int begin = i;
        for (size_t j = 0; j < needle.size(); ++j)
        {
            if (haystack[begin] != needle[j])
            {
                is_equal = false;
                break;
            }
            begin++;
        }

        if (is_equal)
        {
            index = i;
            break;
        }
    }

    return index;
}

int main()
{
    std::string haystack = "hello";
    std::string needle = "ll";
    std::cout << strStr(haystack, needle) << std::endl;
    ;

    return 0;
}