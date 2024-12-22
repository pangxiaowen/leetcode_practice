#include <iostream>
#include <vector>

std::vector<std::string> result;
void tracebacking(std::vector<std::string> vec, int k, int start_index, std::string res)
{
    if (res.size() == k)
    {
        result.push_back(res);
    }

    if (start_index > vec.size() - 1)
        return;

    size_t i = start_index;
    for (auto j = 0; j < vec[i].size(); j++)
    {
        res = res + vec[i][j];
        tracebacking(vec, k, i + 1, res);
        res.pop_back();
    }
}

void letterCombinations(std::vector<int> nums)
{
    std::vector<std::string> vec;
    for (auto it : nums)
    {
        switch (it)
        {
        case 2:
            vec.emplace_back("abc");
            break;
        case 3:
            vec.emplace_back("def");
            break;
        case 4:
            vec.emplace_back("ghi");
            break;
        case 5:
            vec.emplace_back("jkl");
            break;
        case 6:
            vec.emplace_back("mno");
            break;
        case 7:
            vec.emplace_back("pqrs");
            break;
        case 8:
            vec.emplace_back("tuv");
            break;
        case 9:
            vec.emplace_back("wxyz");
            break;
        default:
            break;
        }
    }

    int k = nums.size();

    std::string res;
    tracebacking(vec, k, 0, res);
}

int main()
{
    std::vector<int> nums{2, 3, 9};
    letterCombinations(nums);

    for (auto it : result)
    {
        for (auto i : it)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}