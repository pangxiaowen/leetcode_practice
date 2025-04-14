#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

void print_nums(int x)
{
    int sum = 0;
    while (x != 0)
    {
        int y = x % 10;
        std::cout << y << std::endl;
        x = x / 10;

        sum += y * y;
    }

    std::cout << sum << std::endl;
}

int main()
{
    // 计算hash值
    std::cout << std::hash<std::string>()("pxw") << std::endl;

    print_nums(19);
    return 0;
}