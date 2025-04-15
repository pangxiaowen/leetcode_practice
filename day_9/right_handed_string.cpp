#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>

std::string reverse(std::string str, int k)
{
    std::string s_left(str.begin(), str.end() - k);
    std::string s_right(str.end() - k, str.end());

    return s_right + s_left;
}

std::string reverse_v2(std::string str, int k)
{
    std::reverse(str.begin(), str.end());
    std::reverse(str.begin(), str.begin() + k);
    std::reverse(str.begin() + k, str.end());

    return str;
}

std::string str_reverse(std::string str)
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right)
    {
        std::swap(str[left], str[right]);
        left++;
        right--;
    }

    return str;
}

std::string right_handed_string(std::string str, int k)
{
    // 1.
    std::reverse(str.begin(), str.end());

    // 2.
    std::reverse(str.begin(), str.begin() + k);
    std::reverse(str.begin() + k, str.end());
}

int main()
{
    int k = 2;
    std::string str = "abcdefg";

    std::cout << reverse(str, k) << std::endl;
    std::cout << reverse_v2(str, k) << std::endl;

    std::cout << str_reverse(str) << std::endl;
    return 0;
}