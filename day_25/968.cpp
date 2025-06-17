
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 给定一个二叉树，我们在树的节点上安装摄像头。
// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
// 计算监控树的所有节点所需的最小摄像头数量。

// 思路
// 贪心的思想， 使得摄像头尽可能的覆盖更多的节点

// 因此，摄像头不能出现在叶子节点上
// 采用自底向上的遍历方法， 左右中

// 使用返回值记录节点状态
// 0 没有覆盖
// 1 放置摄像头
// 2 已经覆盖

int result = 0;
int Traversal(TreeNode *node)
{
    if (node == nullptr)
    {
        return 2;
    }

    int l_v = Traversal(node->left);
    int r_v = Traversal(node->right);

    if (l_v == 2 && r_v == 2)
    {
        return 0;
    }

    if (l_v == 0 || r_v == 0)
    {
        result++;
        return 1;
    }

    if (l_v == 1 || r_v == 1)
    {
        return 2;
    }

    return -1;
}

int minCameraCover(TreeNode *root)
{
    Traversal(root);
    return result;
}