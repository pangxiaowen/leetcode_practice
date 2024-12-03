#include <iostream>
#include <map>

bool isAnagram(std::string a, std::string b)
{
    std::map<char, int> count_map;

    for (auto it : a)
    {
        count_map[it]++;
    }

    for (auto it : b)
    {
        count_map[it]--;
    }

    for (auto it : count_map)
    {
        if (it.second != 0)
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