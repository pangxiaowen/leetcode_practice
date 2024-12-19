#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

class TreeNode
{
  public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode() = default;
    TreeNode(int v) : val(v)
    {
    }
};

TreeNode *sortedArrayToBST(std::vector<int> &nums)
{
    if (nums.empty())
        return nullptr;

    int mid_index = nums.size() / 2;
    TreeNode *root = new TreeNode();
    root->val = nums[mid_index];

    if (nums.size() == 1)
        return root;

    std::vector<int> left(mid_index);
    std::copy(nums.begin(), nums.begin() + mid_index, left.begin());
    root->left = sortedArrayToBST(left);

    std::vector<int> right(nums.size() - mid_index);
    std::copy(nums.begin() + mid_index + 1, nums.end(), right.begin());
    root->right = sortedArrayToBST(right);

    return root;
}

int main()
{
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    sortedArrayToBST(nums);

    return 0;
}