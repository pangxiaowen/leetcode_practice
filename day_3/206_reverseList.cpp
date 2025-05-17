#include <iostream>
struct Node
{
    int val;
    Node *next;
};

Node *reverse_list(Node *list)
{
    Node *first = list->next;
    Node *slow = list;

    while (first != nullptr)
    {
        Node *tmp = first->next;
        first->next = slow;

        slow = first;
        first = tmp;
    }

    list->next = nullptr;

    return slow;
}

Node *reverse_list_v2(Node *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;

    Node *last = reverse_list_v2(head->next);

    head->next->next = head;
    head->next = nullptr;

    return last;
}

Node *reverse_list_v3(Node *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;

    Node *last = reverse_list_v3(head->next);

    head->next->next = head;
    head->next = nullptr;
    return last;
}

int main()
{
    Node *head = new Node{0, nullptr};

    Node *cur = head;
    for (size_t i = 1; i < 10; ++i)
    {
        Node *node = new Node{i, nullptr};
        cur->next = node;
        cur = node;
    }

    cur = head;
    while (cur != nullptr)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    cur = reverse_list_v3(head);
    while (cur != nullptr)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    return 0;
}
