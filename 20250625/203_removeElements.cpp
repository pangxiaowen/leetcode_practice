
class ListNode
{
public:
    int val;
    ListNode *next;
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *new_head = new ListNode();
    new_head->next = head;

    ListNode *cur_node = new_head;
    while (cur_node->next != nullptr)
    {
        if (cur_node->next->val == val)
        {
            ListNode *tmp = cur_node->next;
            cur_node->next = cur_node->next->next;
            delete tmp;
        }
        else
        {
            cur_node = cur_node->next;
        }
    }

    return new_head->next;
}