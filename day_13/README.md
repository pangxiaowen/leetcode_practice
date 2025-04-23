# Day_13

## 递归

1. 确定递归函数的参数以及返回值。 确定哪些参数是递归的过程中需要处理的，那么就在递归函数中加上这个参数，并且还要明确每次递归的返回值是什么进而确定递归的返回值类型。

2. 确定终止条件

3. 确定单层递归的逻辑

## 二叉树的递归遍历

```
    void Traversal(TreeNode* node, std::vector<int> &result)
    {
        if(node == nullptr)
            return;
        
        result.push_back(node->val);
        Traversal(node->left, result);
        Traversal(node->right, result);
    }
```

## 二叉树的迭代遍历

递归遍历可能出现栈溢出，因此可以采用迭代遍历的方法。

1. 前序遍历， 中左右

遍历顺序与操作顺序一致，因此较为简洁，访问到中节点时记录即可

```
    std::vector<int> res;
    std::stack<TreeNode *> st;

    if (root == nullptr)
        return res;

    st.push(root);

    while (!st.empty())
    {
        auto node = st.top();
        res.push_back(node->val);
        st.pop();

        if (node->right != nullptr)
        {
            st.push(node->right);
        }

        if (node->left != nullptr)
        {
            st.push(node->left);
        }
    }

    return res;
```

2. 中序遍历， 左中右。

遍历顺序与处理顺序不同，需要先访问到最左边的节点，然后再开始处理。 

那么在使用迭代法写中序遍历，就需要借用指针的遍历来帮助访问节点，栈则用来处理节点上的元素。

```
    std::vector<int> res;
    std::stack<TreeNode *> st;

    if (root == nullptr)
        return res;

    TreeNode *cur = root;

    while (cur != nullptr || !st.empty())
    {
        if (cur != nullptr) // 指针访问节点, 访问到最低层
        {
            st.push(cur);    // 将访问的节点放入栈中
            cur = cur->left; // 向左
        }
        else
        {
            cur = st.top(); // 到达底层, 弹出数据
            st.pop();
            res.push_back(cur->val); // 中
            cur = cur->right;        // 右
        }
    }

    return res;
```

3. 后序遍历， 左右中， --> 中右左的翻转， 可以根据前序修改



## 总结

1. 前序遍历中访问节点（遍历节点）和处理节点（将元素放进result数组中）可以同步处理，但是中序就无法做到同步！

2. 递归与栈的关系！！！

3. 关于迭代的统一写法，使用nullptr或者bool变量标记该节点是否被访问过。
