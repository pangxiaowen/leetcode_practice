#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> partitionLabels(string s)
{
    std::unordered_map<char, int> map;

    for (int i = 0; i < s.size(); ++i)
    {
        map[s[i]] = i;
    }

    int end = map[s[0]];
    int left = 0;

    std::vector<int> res;
    for (int i = 1; i < s.size(); ++i)
    {
        end = std::max(map[s[i]], end);
        if (i == end)
        {
            res.push_back(end - left + 1);
            left = end + 1;
        }
    }

    return res;
}

int main()
{
    std::string s = "ababcbacadefegdehijhklij";

    auto res = partitionLabels(s);

    for (auto it : res)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}