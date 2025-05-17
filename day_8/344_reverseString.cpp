#include <iostream>
#include <string>

void reverse(std::string &str)
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right)
    {
        std::swap(str[left], str[right]);
        left++;
        right--;
    }
}

int main()
{
    std::string str = "hello";
    std::cout << str << std::endl;

    reverse(str);
    std::cout << str << std::endl;
}