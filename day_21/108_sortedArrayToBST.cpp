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
    TreeNode(int v) : val(v) {}
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

TreeNode *Traversal(std::vector<int> &nums, int l, int r)
{
    if (l > r)
        return nullptr;

    // 可能越界
    // int mid = (l + r) / 2;
    int mid = l + (r - l) / 2;
    TreeNode *node = new TreeNode();
    node->val = nums[mid];

    node->left = Traversal(nums, l, mid - 1);
    node->right = Traversal(nums, mid + 1, r);

    return node;
}

TreeNode *sortedArrayToBSTv2(std::vector<int> &nums)
{
    if (nums.empty())
        return nullptr;

    int mid = nums.size() / 2;
    TreeNode *node = new TreeNode();
    node->val = nums[mid];

    if (mid == 0)
        return node;

    std::vector<int> left{nums.begin(), nums.begin() + mid};
    node->left = sortedArrayToBSTv2(left);

    if (mid + 1 < nums.size())
    {
        std::vector<int> right{nums.begin() + mid + 1, nums.end()};
        node->right = sortedArrayToBSTv2(right);
    }

    return node;
}