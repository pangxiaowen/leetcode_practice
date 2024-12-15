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
};

// 二叉搜索树的中序遍历是有序的，通过中序遍历把结果存下来，然后判断众数
int count = 1;
int max_count = 1;
TreeNode *pre = nullptr;
std::vector<int> result;
void traversal(TreeNode *node)
{
    if (node == nullptr)
        return;

    traversal(node->left);

    if (pre != nullptr)
    {
        if (pre->val == node->val)
        {
            count++;
        }
        else
        {
            if (count > max_count)
            {
                max_count = count;
                result.clear();
                result.push_back(node->val);
            }
            else if (count == max_count)
            {
                result.push_back(node->val);
            }

            // 记录当前的pre值, 以及count值
            count = 1;
        }
    }

    pre = node;

    traversal(node->right);
}

std::unordered_map<int, int> map;
void searchBST(TreeNode *node)
{
    if (node == nullptr)
        return;

    map[node->val]++;
    searchBST(node->left);
    searchBST(node->right);
}

std::vector<int> find_model(TreeNode *root)
{
    searchBST(root);

    std::vector<std::pair<int, int>> count;
    for (auto it : map)
    {
        count.push_back({it.first, it.second});
    }

    auto func = [](const std::pair<int, int> &a, std::pair<int, int> &b) { return a.second > b.second; };
    std::sort(count.begin(), count.end(), func);

    int max = count[0].second;
    std::vector<int> result;
    for (auto it : count)
    {
        if (it.second == max)
            result.push_back(it.first);
    }

    return result;
}