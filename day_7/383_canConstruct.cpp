#include <iostream>
#include <unordered_map>
#include <unordered_set>

bool can_construct(std::string a, std::string b)
{
    std::unordered_map<char, int> tmp;
    for (auto it : a)
    {
        tmp[it]++;
    }

    for (auto it : b)
    {
        auto iter = tmp.find(it);
        if (iter != tmp.end())
        {
            iter->second--;
        }
    }

    for (auto it : tmp)
    {
        if (it.second > 0)
        {
            return false;
        }
    }

    return true;
}

bool can_construct_v2(std::string a, std::string b)
{
    if (a.size() > b.size())
        return false;

    // 可以考虑使用数组，消耗更小
    int tmp[26]{0};

    for (size_t i = 0; i < b.size(); ++i)
    {
        tmp[b[i] - 'a']++;
    }

    for (size_t i = 0; i < a.size(); ++i)
    {
        tmp[a[i] - 'a']--;
        if (tmp[a[i] - 'a'] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string a = "aa";
    std::string b = "abab";
    std::cout << can_construct_v2(a, b) << std::endl;
    return 0;
}