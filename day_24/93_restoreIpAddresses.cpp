#include <iostream>
#include <vector>

std::vector<std::string> result;

bool is_vaild(const std::string &s, int start, int end)
{
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
    if (point_num == 3)
    {
        if (is_vaild(str, start_index, str.size() - 1))
        {
            result.push_back(str);
        }
        return;
    }

    for (size_t i = start_index; i < str.size(); ++i)
    {
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
    std::string str{"25525511135"};
    auto res = restoreIpAddresses(str);
    for (auto it : res)
    {
        std::cout << it << std::endl;
    }
    return 0;
}