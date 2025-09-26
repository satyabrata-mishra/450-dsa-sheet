struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        head = reverse(head);
        int maxData = head->data;
        Node *curr = head->next;
        Node *prev = head;
        while (curr != nullptr)
        {
            if (maxData > curr->data)
            {
                prev->next = curr->next;
            }
            else
            {
                maxData = curr->data;
                prev = curr;
            }
            curr = curr->next;
        }
        head = reverse(head);
        return head;
    }
};