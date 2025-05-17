#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> result;

bool is_vaild(const std::string &s, int start, int end)
{
    // 如果只有一位数字，均为true
    if (start == end)
        return true;

    // 位数大于1，先导为0
    if (s[start] == '0')
        return false;

    std::string sub_str = s.substr(start, end - start + 1);
    double val = std::stod(sub_str);
    if (val > 0 && val <= 256)
    {
        return true;
    }

    return false;
}

void backtracking(std::string &str, int start_index, int point_num)
{
    // 如果已经插入了3个"."
    if (point_num == 3)
    {
        // 判断剩下的部分是否符合要求
        if (is_vaild(str, start_index, str.size() - 1))
        {
            result.push_back(str);
        }
        return;
    }

    for (size_t i = start_index; i < str.size(); ++i)
    {
        // 判断start_index 到 i 之间的部分是否满足要求。
        if (is_vaild(str, start_index, i))
        {
            point_num++;
            str.insert(str.begin() + i + 1, ',');
            backtracking(str, i + 2, point_num);
            str.erase(str.begin() + i + 1);
            point_num--;
        }
        else
        {
            break;
        }
    }
}

std::vector<std::string> restoreIpAddresses(std::string s)
{
    backtracking(s, 0, 0);
    return result;
}

int main()
{
    std::string str{"0000"};
    auto res = restoreIpAddresses(str);
    for (auto it : res)
    {
        std::cout << it << std::endl;
    }
    return 0;
}

namespace pxw
{
std::vector<std::string> result;
std::string str;

bool is_valid(const std::string &s)
{
    if (s.size() == 1)
        return true;

    if (s[0] == '0')
        return false;

    double num = std::stod(s);
    if (num < 0 || num > 255)
        return false;

    return true;
}

void backTracking(const std::string &s, int startIndex)
{
    if (str.size() == (s.size() + 4) && startIndex == s.size())
    {
        str.pop_back();
        result.push_back(str);
        return;
    }

    for (int i = startIndex; i < s.size(); ++i)
    {
        std::string sub_str = s.substr(startIndex, i - startIndex + 1);

        if (is_valid(sub_str))
        {
            std::string tmp = str;
            str += sub_str + ".";
            backTracking(s, i + 1);
            str = tmp;
        }
    }
}
} // namespace pxw