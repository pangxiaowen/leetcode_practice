#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int i) : val{i}, next{nullptr}
    {
    }
};

ListNode *remove_nth(ListNode *head, int n)
{
    if (head == nullptr)
        return head;

    ListNode *dummy_node = new ListNode(0);
    dummy_node->next = head;

    ListNode *first = dummy_node;
    ListNode *slow = dummy_node;

    while (first->next != nullptr)
    {
        first = first->next;
        if (n == 0)
        {
            slow = slow->next;
        }
        else
        {
            n--;
        }
    }

    ListNode *tmp = slow->next;
    slow->next = slow->next->next;

    head = dummy_node->next;
    delete dummy_node;

    return head;
}

// 链表非空的判断
ListNode *remove_nth_v2(ListNode *head, int n)
{
    ListNode *dummy_node = new ListNode(0);
    dummy_node->next = head;

    ListNode *first = dummy_node;
    ListNode *slow = dummy_node;

    // 先将first 往前移动n
    while (n-- && first != nullptr)
    {
        first = first->next;
    }

    // 再将first往前移动一格, 这样slow就指向需要伤处节点的前一个节点
    first = first->next;

    while (first != nullptr)
    {
        first = first->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return dummy_node->next;
}

int main()
{
    ListNode *head = new ListNode(1);

    ListNode *cur = head;
    for (size_t i = 2; i < 1; i++)
    {
        ListNode *node = new ListNode(i);
        cur->next = node;
        cur = cur->next;
    }

    cur = head;
    while (cur != nullptr)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    cur = remove_nth(head, 1);
    while (cur != nullptr)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    return 0;
}