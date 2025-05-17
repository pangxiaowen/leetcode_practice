#include <cstddef>
#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string s)
{
    bool result = false;
    for (size_t i = 0; i < (s.size() + 1) / 2; ++i)
    {
        if ((s.size() % (i + 1)) != 0)
            continue;

        result = true;
        for (size_t j = 0; j < s.size(); ++j)
        {
            if (s[j % (i + 1)] != s[j])
            {
                result = false;
                break;
            }
        }

        if (result)
            break;
    }

    return result;
}

int main()
{
    std::string s = "abaababaab";
    std::cout << repeatedSubstringPattern(s) << std::endl;
}