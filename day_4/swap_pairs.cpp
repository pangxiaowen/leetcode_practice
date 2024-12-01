#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int i) : val{i}, next{nullptr}
    {
    }
};

ListNode *swap_pairs(ListNode *head)
{
    ListNode *dummy_node = new ListNode(0);
    dummy_node->next = head;

    ListNode *cur = dummy_node;
    while (cur->next != nullptr && cur->next->next != nullptr)
    {
        ListNode *tmp = cur->next->next->next;

        cur->next->next->next = cur->next;
        cur->next = cur->next->next;
        cur->next->next->next = tmp;

        cur = cur->next->next;
    }

    head = dummy_node->next;
    delete dummy_node;

    return head;
}

ListNode *swap_paris_v2(ListNode *head)
{
    ListNode *dummy_node = new ListNode(0);
    dummy_node->next = head;

    ListNode *cur = dummy_node;
    while (cur->next != nullptr && cur->next->next != nullptr)
    {
        ListNode *tmp = cur->next;
        ListNode *tmp_1 = cur->next->next->next;

        cur->next = cur->next->next;
        cur->next->next = tmp;
        cur->next->next->next = tmp_1;

        cur = cur->next->next;
    }

    head = dummy_node->next;
    delete dummy_node;

    return head;
}

int main()
{
    ListNode *head = new ListNode(1);

    ListNode *cur = head;
    for (size_t i = 2; i < 20; i++)
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

    // swap_pairs(head);

    cur = swap_paris_v2(head);
    while (cur != nullptr)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    return 0;
}