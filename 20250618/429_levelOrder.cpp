#include <queue>
#include <stack>
#include <vector>

class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

std::vector<std::vector<int>> levelOrder(Node *root)
{
    std::vector<std::vector<int>> result;
    if (root == nullptr)
        return result;

    std::queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        std::vector<int> tmp;
        for (int i = 0; i < size; i++)
        {
            auto cur = que.front();
            que.pop();
            tmp.push_back(cur->val);

            for (auto it : cur->children)
            {
                que.push(it);
            }
        }

        result.push_back(tmp);
    }
    return result;
}