#include <algorithm>
#include <cstdint>
#include <list>
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

// 给你一个整数数组 nums ，其中元素已经按升序排列，请你将其转换为一棵平衡二叉搜索树。

TreeNode *Traversal(const std::vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    TreeNode *node = new TreeNode();
    int index = (end + start) / 2;
    node->val = nums[index];

    node->left = Traversal(nums, start, index - 1);
    node->right = Traversal(nums, index + 1, end);

    return node;
}

TreeNode *sortedArrayToBST(std::vector<int> &nums)
{
    // 一直取中间元素作为节点
    TreeNode *root = Traversal(nums, 0, nums.size() - 1);
    return root;
}

int main()
{
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    sortedArrayToBST(nums);
}
