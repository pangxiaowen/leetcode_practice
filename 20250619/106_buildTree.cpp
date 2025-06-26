#include <algorithm>
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

// 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder
// 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

// 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// 输出：[3,9,20,null,null,15,7]

TreeNode *Traversal(std::vector<int> inorder, std::vector<int> postorder)
{
    if (inorder.size() == 0 && postorder.size() == 0)
        return nullptr;

    TreeNode *root = new TreeNode();

    root->val = postorder[postorder.size() - 1];

    auto pos = std::find(inorder.begin(), inorder.end(), root->val);
    int left_size = pos - inorder.begin();
    int right_size = inorder.size() - 1 - left_size;

    root->left = Traversal({inorder.begin(), inorder.begin() + left_size},
                           {postorder.begin(), postorder.begin() + left_size});

    root->right =
        Traversal({pos + 1, inorder.end()}, {postorder.begin() + left_size, postorder.end() - 1});

    return root;
}

TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
    return Traversal(inorder, postorder);
}

int main()
{
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    std::vector<int> postorder = {9, 15, 7, 20, 3};
    buildTree(inorder, postorder);
}