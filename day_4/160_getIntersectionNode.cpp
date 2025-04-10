#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int i) : val{i}, next{nullptr} {}
};

ListNode *get_intersection_node(ListNode *A, ListNode *B)
{
    int len_a, len_b;

    ListNode *cur_a = A;
    ListNode *cur_b = B;
    while (cur_a != nullptr)
    {
        cur_a = cur_a->next;
        len_a++;
    }

    while (cur_b != nullptr)
    {
        cur_b = cur_b->next;
        len_b++;
    }

    int distance = std::abs(len_a - len_b);

    cur_a = A;
    cur_b = B;
    if (len_a > len_b)
    {
        while (distance--)
        {
            cur_a = cur_a->next;
        }
    }
    else
    {
        while (distance--)
        {
            cur_b = cur_b->next;
        }
    }

    while (cur_a != nullptr && cur_b != nullptr)
    {
        if (cur_a == cur_b)
            break;

        cur_a = cur_a->next;
        cur_b = cur_b->next;
    }

    return cur_a;
}

ListNode *get_intersection_node_v2(ListNode *A, ListNode *B)
{
    ListNode *cur_a = A;
    ListNode *cur_b = B;

    while (cur_a != cur_b)
    {
        cur_a = cur_a == nullptr ? B : cur_a->next;
        cur_b = cur_b == nullptr ? A : cur_b->next;
    }

    return cur_a;
}

int main()
{
    ListNode *A = new ListNode(1);
    ListNode *B = new ListNode(1);

    ListNode *cur_a = A;
    for (size_t i = 2; i < 5; i++)
    {
        ListNode *node = new ListNode(i);
        cur_a->next = node;
        cur_a = cur_a->next;
    }

    ListNode *cur_b = B;
    for (size_t i = 2; i < 3; i++)
    {
        ListNode *node = new ListNode(i);
        cur_b->next = node;
        cur_b = cur_b->next;
    }

    for (size_t i = 2; i < 7; i++)
    {
        ListNode *node = new ListNode(i);
        cur_b->next = node;
        cur_a->next = node;

        cur_a = cur_a->next;
        cur_b = cur_b->next;
    }

    cur_a = A;
    cur_b = B;

    while (cur_a != nullptr)
    {
        std::cout << cur_a->val << " ";
        cur_a = cur_a->next;
    }
    std::cout << std::endl;

    while (cur_b != nullptr)
    {
        std::cout << cur_b->val << " ";
        cur_b = cur_b->next;
    }
    std::cout << std::endl;

    auto res = get_intersection_node(A, B);
    std::cout << res->val << std::endl;

    return 0;
}