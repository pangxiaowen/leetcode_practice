#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

bool isAnagram(std::string s, std::string t)
{
    if (s.size() != t.size())
        return false;

    std::unordered_map<char, int> map;
    for (size_t i = 0; i < s.size(); ++i)
    {
        map[s[i]]++;
        map[t[i]]--;
    }

    for (const auto &it : map)
    {
        if (it.second < 0)
            return false;
    }

    return true;
}

int main()
{
    std::string a = "anagram";
    std::string b = "nagaram";

    std::cout << isAnagram(a, b) << std::endl;
    return 0;
}