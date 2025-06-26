#include <cstdint>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *Traversal(std::vector<int> nums, int start, int end)
{
    if (end <= start)
        return nullptr;

    TreeNode *root = new TreeNode();
    root->val = INT32_MIN;

    int index = 0;
    for (int i = start; i < end; i++)
    {
        if (nums[i] > root->val)
        {
            root->val = nums[i];
            index = i;
        }
    }

    root->left = Traversal(nums, start, index);
    root->right = Traversal(nums, index + 1, end);

    return root;
}

TreeNode *constructMaximumBinaryTree(std::vector<int> &nums)
{
    return Traversal(nums, 0, nums.size());
}