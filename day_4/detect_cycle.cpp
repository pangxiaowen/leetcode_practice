#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int i) : val{i}, next{nullptr}
    {
    }
};

ListNode *detect_cycle(ListNode *head)
{
    ListNode *first = head;
    ListNode *slow = head;

    while (first != nullptr && first->next != nullptr)
    {
        slow = slow->next;
        first = first->next->next;
        if (slow == first) // 若快慢指针相等, 则有环
        {
            ListNode *a = head;
            ListNode *b = slow;

            while (a == b)
            {
                a = a->next;
                b = b->next;
            }

            return a;
        }
    }

    return nullptr;
}