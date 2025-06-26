#include <queue>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next)
    {
    }
};

Node *connect(Node *root)
{
    if (root == nullptr)
        return root;

    std::queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        int size = que.size();

        Node *next = nullptr;
        for (int i = 0; i < size; i++)
        {
            auto cur = que.front();
            que.pop();

            cur->next = next;
            next = cur;

            if (cur->right != nullptr)
                que.push(cur->right);
            if (cur->left != nullptr)
                que.push(cur->left);
        }
    }

    return root;
}