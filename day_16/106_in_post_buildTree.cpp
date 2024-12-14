#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class TreeNode
{
  public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

TreeNode *traversal(std::vector<int> &inorder, std::vector<int> &postorder)
{
    if (postorder.size() == 0)
        return nullptr;

    TreeNode *root = new TreeNode();
    root->val = postorder[postorder.size() - 1]; // 后序的最后一个值是 父节点

    postorder.resize(postorder.size() - 1); // 将最后一个节点删除

    // 根据父节点进行切割 inorder
    auto inorder_index = std::find(inorder.begin(), inorder.end(), root->val); // 找到父节点的位置, 分成左右两边
    std::vector<int> inorder_left{inorder.begin(), inorder_index};             // 0 ~ index-1
    std::vector<int> inorder_right{inorder_index + 1, inorder.end()};          // index + 1 ~ end

    auto postorder_index = postorder.end();
    if (!inorder_right.empty())
        postorder_index = std::find(postorder.begin(), postorder.end(), inorder_right[0]); // 寻找父节点的位置

    std::vector<int> postorder_left{postorder.begin(), postorder_index}; // 分为左右两边
    std::vector<int> postorder_right{postorder_index, postorder.end()};

    root->left = traversal(inorder_left, postorder_left);
    root->right = traversal(inorder_right, postorder_right);

    return root;
}

TreeNode *traversal_v2(std::vector<int> &&inorder, std::vector<int> &&postorder)
{
    if (postorder.size() == 0)
        return nullptr;

    TreeNode *root = new TreeNode();
    root->val = postorder[postorder.size() - 1]; // 后序的最后一个值是 父节点

    postorder.resize(postorder.size() - 1); // 将最后一个节点删除

    // 根据父节点进行切割 inorder
    auto inorder_index = std::find(inorder.begin(), inorder.end(), root->val); // 找到父节点的位置, 分成左右两边
    // std::vector<int> inorder_left{inorder.begin(), inorder_index};             // 0 ~ index-1
    // std::vector<int> inorder_right{inorder_index + 1, inorder.end()};          // index + 1 ~ end

    // auto postorder_index = postorder.end();
    // if (!inorder_right.empty())
    //     postorder_index = std::find(postorder.begin(), postorder.end(), inorder_right[0]); // 寻找父节点的位置

    // std::vector<int> postorder_left{postorder.begin(), postorder_index}; // 分为左右两边
    // std::vector<int> postorder_right{postorder_index, postorder.end()};

    root->left = traversal_v2({inorder.begin(), inorder_index},
                              {postorder.begin(), postorder.begin() + (inorder_index - inorder.begin())});
    root->right = traversal_v2({inorder_index + 1, inorder.end()},
                               {postorder.begin() + (inorder_index - inorder.begin()), postorder.end()});

    return root;
}

int main()
{

    std::vector<int> inorder{9, 3, 15, 20, 7};
    std::vector<int> postorder{9, 15, 7, 20, 3};

    auto root = traversal_v2(std::move(inorder), std::move(postorder));

    std::stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();

        std::cout << cur->val << std::endl;

        if (cur->right != nullptr)
            st.push(cur->right);
        if (cur->left != nullptr)
            st.push(cur->left);
    }

    return 0;
}