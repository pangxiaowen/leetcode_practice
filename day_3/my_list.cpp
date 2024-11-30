#include <iostream>

struct Node
{
  public:
    int val;
    Node *next;
    Node(int i) : val{i}, next{nullptr} {};
};

class MyLinkedList
{
  public:
    int get(int index)
    {
        if (index < 0 || index > m_length)
            return -1;

        Node *cur = m_head;
        for (size_t i = 0; i < index; i++)
        {
            cur = cur->next;
        }

        return cur->val;
    }

    void addAtHead(int val)
    {
        Node *node = new Node(val);
        node->next = m_head;
        m_head = node;
        m_length++;
    }

    void addAtTaile(int val)
    {
        Node *cur = m_head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        Node *node = new Node(val);
        cur->next = node;
        m_length++;
    }

    int addAtIndex(int index, int val)
    {
        if (index > m_length)
            return -1;

        Node *dummy_node = new Node(0);
        dummy_node->next = m_head;
        Node *cur = dummy_node;
        for (size_t i = 0; i < index; i++)
        {
            cur = cur->next;
        }

        Node *node = new Node(val);
        node->next = cur->next;
        cur->next = node;
        m_length++;

        delete dummy_node;
        return 0;
    }

    int deleteAtIndex(int index)
    {
        if (index < 0 || index > m_length)
            return -1;

        Node *dummy_node = new Node(0);
        dummy_node->next = m_head;
        Node *cur = dummy_node;

        for (size_t i = 0; i < index; i++)
        {
            cur = cur->next;
        }

        Node *tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;

        return 0;
    }

    void print()
    {
        Node *cur = m_head;
        while (cur != nullptr)
        {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

  private:
    Node *m_head = nullptr;
    int m_length = 0;
};

class MyLinkedList_v2
{
  public:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val{val}, next{nullptr}
        {
        }
    };

    MyLinkedList_v2()
    {
        m_dummyHead = new LinkedNode(0);
        m_size = 0;
    }

    int get(int index)
    {
        if (index > (m_size - 1) || index < 0)
        {
            return -1;
        }

        LinkedNode *cur = m_dummyHead->next;

        while (index--)
        {
            cur = cur->next;

            return cur->val;
        }
    }

    void addAtHead(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = m_dummyHead->next;
        m_dummyHead->next = newNode;
        m_size++;
    }

    void addAtTail(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = m_dummyHead;

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        cur->next = newNode;
        m_size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > m_size)
            return;

        if (index < 0)
            index = 0;

        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = m_dummyHead;
        while (index--)
        {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode->next;
        m_size++;
    }

    void deletecAtIndex(int index)
    {
        if (index > m_size || index < 0)
            return;

        LinkedNode *cur = m_dummyHead;
        while (index--)
        {
            cur = cur->next;
        }

        LinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        m_size++;
    }

    void printLinkList()
    {
        LinkedNode *cur = m_dummyHead;
        while (cur->next != nullptr)
        {
            std::cout << cur->next->val << "";
            cur = cur->next;
        }
    }

  private:
    int m_size;
    LinkedNode *m_dummyHead;
};

int main()
{
    MyLinkedList list;

    list.addAtHead(0);
    list.addAtHead(1);
    list.addAtHead(2);
    list.addAtHead(3);

    list.addAtTaile(4);
    list.addAtTaile(5);
    list.addAtTaile(6);
    list.addAtTaile(7);
    list.print();

    list.addAtIndex(3, 0);
    list.print();

    std::cout << list.get(7) << std::endl;

    list.deleteAtIndex(7);
    list.print();

    int x = 1;
    while (--x)
    {
        std::cout << x << std::endl;
    }

    return 0;
}