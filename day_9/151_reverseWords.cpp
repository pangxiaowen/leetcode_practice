#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string reverseWords(std::string s)
{
    std::vector<std::string> vec;
    std::stringstream ss;

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] != ' ')
        {
            ss << s[i];
        }

        if (s[i] == ' ' || i == s.size() - 1)
        {
            if (!ss.str().empty())
            {
                vec.push_back(ss.str());
                ss.str("");
                ss.clear();
            }
        }
    }
    ss.clear();

    for (int i = vec.size() - 1; i >= 0; --i)
    {
        ss << vec[i];

        if (i != 0)
        {
            ss << ' ';
        }
    }

    return ss.str();
}

void reverse(std::string &s, int begin, int end)
{
    while (begin < end)
    {
        std::swap(s[begin], s[end]);
        begin++;
        end--;
    }
}

void removeExtraSpace(std::string &s)
{
    int slow = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        // 找到不是空格的元素
        if (s[i] != ' ')
        {
            // 如果slow不是开头元素，则插入一个空格
            if (slow != 0)
            {
                s[slow] = ' ';
                slow++;
            }

            // 从i开始遍历，直到遍历到空格，在此期间元素逐个复制。
            while (s[i] != ' ' && i < s.size())
            {
                s[slow] = s[i];
                slow++;
                i++;
            }
        }
    }

    // slow 就是最终元素的大小
}

std::string reverseWords_v2(std::string s)
{
    if (s.empty())
        return s;

    // 1. 移除多余的空格
    int fast = 0;
    int slow = 0;

    // 找到第一个不是空格的数据
    while (s[fast] == ' ' && fast < s.size())
    {
        fast++;
    }

    // 使用双指针法, 去除中间的结果, 如果s[i] == s[i-1] && s[i] == ' ',
    // 说明遇到了连续的空格，因此fast进行++， slow不变
    for (size_t i = fast; i < s.size();)
    {
        // 保证i -1 存在 i - 1 >
        // s[i] == s[i - 1] && s[i] == ' ' 判断是否存在连续的空格
        if (i - 1 > 0 && s[i] == s[i - 1] && s[i] == ' ')
        {
            ++i;
        }
        {
            s[slow] = s[i];
            ++i;
            slow++;
        }
    }

    // s进行resize 保留去掉空格后的结果
    if (s[s.size() - 1] == ' ') // 如果尾部是空格，slow要减去1
        slow--;

    s.resize(slow);

    // 2. 反转整个string
    reverse(s, 0, s.size() - 1);

    // 3. 逐个反转单词
    int begin = 0;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            // TODO reverse
            reverse(s, begin, i - 1);
            begin = i + 1;
        }

        if (i == s.size() - 1)
        {
            reverse(s, begin, i);
        }
    }
    return s;
}

int main()
{
    std::string str = "the sky is blue";
    std::cout << reverseWords_v2(str) << std::endl;
    return 0;
}
