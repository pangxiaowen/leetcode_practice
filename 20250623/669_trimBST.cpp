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

// 给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L,
// R]中 (R>=L) 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    // 先将root移动到[low, hight]区间内
    while (root != nullptr && (root->val < low || root->val > high))
    {
        if (root->val < low)
        {
            root = root->right;
        }
        else if (root->val > high)
        {
            root = root->left;
        }
    }

    TreeNode *cur = root;

    // 修剪左子树
    while (cur != nullptr)
    {
        // 如果左孩子的值小于low, 则用左孩子的右子树木，代替左孩子
        while (cur->left != nullptr && cur->left->val < low)
        {
            cur->left = cur->left->right;
        }

        // 如果左孩子<low, 则对左孩子的子树继续修改。因为左孩子的左子树有可能不满足要求。
        cur = cur->left;
    }

    cur = root;
    while (cur != nullptr)
    {
        // 如果右孩子的值大于high， 则用右孩子的左子树，代替右孩子
        while (cur->right != nullptr && cur->right->val > high)
        {
            cur->right = cur->right->left;
        }

        // 继续修剪
        cur = cur->right;
    }

    return root;
}