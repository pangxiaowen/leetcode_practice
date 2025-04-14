#include <algorithm>
#include <iostream>
#include <string>

// 当需要固定规律一段一段去处理字符串的时候，要想想在在for循环的表达式上做做文章。
std::string reverse_2(std::string str, int k)
{
    for (int i = 0; i < str.size(); i = i + 2 * k)
    {
        if (i + k < str.size())
        {
            // 如果剩余字符小于2k但是大于等于k, 则反转前k个，其余字符保持原样
            // 从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。
            std::reverse(str.begin() + i, str.begin() + i + k);
        }
        else
        {
            // 如果剩余字符少于K,则将字符全部反转
            std::reverse(str.begin() + i, str.end());
        }
    }

    return str;
}

int main()
{
    std::string str = "abcdefg";
    auto res = reverse_2(str, 2);
    std::cout << res << std::endl;
}