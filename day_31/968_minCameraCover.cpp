#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int result;
int traveral(TreeNode *cur)
{
    if (cur == nullptr) // 如果当前节点为空，则认为已经被覆盖
        return 2;

    int left = traveral(cur->left);
    int right = traveral(cur->right);

    // 左右节点均被覆盖, 当前节点未覆盖
    if (left == 2 && right == 2)
        return 0;

    // 左或右节点没有被覆盖，在此节点安排摄像头
    if (left == 0 || right == 0)
    {
        result++;
        return 1;
    }

    // 如果左或右节点有摄像头，则当前节点被覆盖
    if (left == 1 || right == 1)
    {
        return 2;
    }

    return -1;
}

int minCameraCover(TreeNode *root)
{
    result = 0;
    if (traveral(root) == 0) // 如果root没有被覆盖，则在root防止摄像头
    {
        result++;
    }

    return result;
}