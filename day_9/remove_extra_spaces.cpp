#include <iostream>
#include <string>
#include <algorithm>

// 移除多余的空格
// 将整个字符串反转
// 将每个单词反转
std::string remove_extra_space(std::string str)
{
    // 删除连续的空格
    for (size_t i = str.size() - 1; i > 0; --i)
    {
        if (str[i] == str[i - 1] && str[i] == ' ')
        {
            str.erase(str.begin() + i);
        }
    }

    // 删除字符串后面的空格
    if (str.size() > 0 && str[str.size() - 1] == ' ')
        str.erase(str.begin() + str.size() - 1);

    // 删除字符串前面的空格
    if (str.size() > 0 && str[0] == ' ')
        str.erase(str.begin());

    // 反转字符串
    std::reverse(str.begin(), str.end());

    // 反转单词
    int start = 0;
    for (int i = 0; i <= str.size(); ++i)
    {
        if (i == str.size() || str[i] == ' ')
        {
            // 左闭右开
            std::reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
    }

    return str;
}

int main()
{
    std::string str = "the sky is blue";
    std::cout << remove_extra_space(str) << std::endl;
}