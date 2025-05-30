# Day_16

## 找树左下角的值

### 题目

给定一个二叉树，在树的最后一行找到最左边的值。

### 思路

1. 递归， 前中后序都可以，因为都是有优先左边去遍历的，当第一次达到最大深度的时候，记录当前值即可。
2. 层序遍历，记录最后一层的第一个即可。

## 路径总和

### 题目

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

### 思路

1. 递归，分解子问题，判断子树，是否存在 target - cur->val的路径，直到叶子节点
2. 当遍历到叶子节点的时候， target - cur->val 等于0，说明存在一条这样的路径。
3. 迭代法，如何回溯路径？此时栈里一个元素不仅要记录该节点指针，还要记录从头结点到该节点的路径数值总和。引入一个st_sum，用于记录当前节点的路径和
```
    std::stack<TreeNode*> st_node;
    std::stack<int> st_sum;
```

## 从中序与后序遍历序列构造二叉树

### 题目

根据一棵树的中序遍历与后序遍历构造二叉树。

注意: 你可以假设树中没有重复的元素。

### 思路

1. 根据后序的性质，最后一个元素是顶点
2. 根据顶点在中序列中的位置，划分出左右子树
3. 根据左右子树的长度，在后序中划分出左右子树
4. 递归进行处理。

## 从前序与中序遍历序列构造二叉树

同上
