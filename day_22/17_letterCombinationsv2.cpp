#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<int, std::string> num2str = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"},
};

std::vector<std::string> result;
std::string str;

void traceBacking(const std::vector<int> &nums, int start_index)
{
    if (str.size() == nums.size())
    {
        result.push_back(str);
        return;
    }

    for (int j = 0; j < num2str[nums[start_index]].size(); j++)
    {
        str.push_back(num2str[nums[start_index]][j]);
        traceBacking(nums, start_index + 1);
        str.pop_back();
    }
}

void letterCombinations(std::vector<int> nums) { traceBacking(nums, 0); }

int main()
{

    std::vector<int> nums{2, 3};
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