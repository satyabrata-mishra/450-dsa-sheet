class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *temp = nullptr;
        while (curr != nullptr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp != nullptr)
            head = temp->prev;
        return head;
    }
};