#include <cstddef>
class Node
{
public:
    int val;
    Node *next;
};

class MyLinkedList
{
public:
    MyLinkedList()
    {
        m_head = new Node();
        m_len = 0;
    }

    int get(int index)
    {
        if (index > m_len - 1 || index < 0)
            return -1;

        Node *cur = m_head->next;
        while (index--)
        {
            cur = cur->next;
        }

        return cur->val;
    }

    void addAtHead(int val)
    {
        Node *node = new Node();
        node->val = val;

        node->next = m_head->next;
        m_head->next = m_head;
        m_len++;
    }

    void addAtTail(int val)
    {
        Node *node = new Node();
        node->val = val;

        Node *cur = m_head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        cur->next = node;
        m_len++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > m_len)
            return;

        if (index < 0)
            index = 0;

        Node *node = new Node();
        node->val = val;

        Node *cur = m_head;
        while (index--)
        {
            cur = cur->next;
        }

        node->next = cur->next;
        cur->next = node;
        m_len++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= m_len || index < 0)
            return;

        Node *cur = m_head;
        while (index--)
        {
            cur = cur->next;
        }

        Node *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        m_len--;
    }

private:
    Node *m_head = nullptr;
    size_t m_len;
};
