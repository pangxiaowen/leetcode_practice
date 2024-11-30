#

## Day_3

### 移除列表元素

    1. 单链表 删除当前节点需要知道上一节点和下一节点, 下一节点的信息又next指针提供, 而上一节点无法直接访问，因此采用node->next 的方式访问当前节点,
    node是上一节点, node->next 是当前节点, node->next->next 是下一个节点
    2. 头节点的删除和其他节点不一致，因为头节点不存在上一个节点。因此删除的时候有两种方式:
        1. 判断若删除的节点是头节点,则进行特殊的处理, 将指针后移, 然后删除头节点
        2. 插入一个虚拟头节点, 补上头节点的上一个节点, 使得删除操作保持一致
    
### 设计链表

    实现
    1. get(index), 获取链表中第index个节点的值。如果索引无效,则返回-1
    2. addAtHead(val)    在链表的第一个元素之前添加一个值为val的节点。
    插入后, 新节点将变成链表的第一个节点
    3. addAtTaile(val) 将值为 val 的节点追加到链表的最后一个元素。
    4. addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
    5. deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

    使用虚拟头节点进行实现
    
### 链表反转

1. 双指针法
一个指针在前 fast_ptr, 一个指针在后 slow_ptr
使用tmp = fast_ptr->next, 记录要访问的下一个节点
tmp = fast_ptr->next,
fast_ptr->next = slow_ptr;
slow_ptr = fast_ptr
fast_ptr = tmp

2. 递归法
    head == nullptr 此条件只要用于判断链表是否为空, 并非递归的终止条件
    递归的终止条件: head->next == nullptr  此处为递归的终止条件, 当访问到最后一个元素的时候, 终止递归
    // 递归调用，翻转第二个节点开始往后的链表
    ListNode *last = reverseList(head->next);
    链表的反转: head->next->next = head;
    // 此时的 head 节点为尾节点，next 需要指向 NULL
    head->next = NULL;  随着递归的进行, 链表从后往前, 依次断开初始的链接
