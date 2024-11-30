#include <iostream>
#include <memory>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int i) : val(i), next(nullptr)
    {
    }
};

ListNode *removeElements(ListNode *head, int target)
{
    ListNode *dummy_head = new ListNode(0);
    dummy_head->next = head;

    ListNode *cur = dummy_head;
    while (cur->next != nullptr)
    {
        if (cur->next->val == target)
        {
            ListNode *tmp = cur->next;
            cur->next = tmp->next->next;
            delete tmp;
        }
        else
        {
            cur = cur->next;
        }
    }

    head = dummy_head->next;
    delete dummy_head;

    return head;
}

ListNode *removeElements_v2(ListNode *head, int target)
{
    ListNode *dummy_node = new ListNode(0);
    dummy_node->next = head;

    ListNode *cur = dummy_node;

    while (cur->next != nullptr)
    {
        if (cur->next->val == target)
        {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        }
        else
        {
            cur = cur->next;
        }
    }

    head = dummy_node->next;
    return head;
}

int main()
{
    ListNode *head = new ListNode(0);

    ListNode *cur = head;
    for (size_t i = 0; i < 10; i++)
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

    head = removeElements_v2(head, 0);

    cur = head;
    while (cur != nullptr)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    return 0;
}