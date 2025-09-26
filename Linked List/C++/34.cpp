struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    int length(Node *head)
    {
        Node *temp = head;
        int len = 0;
        while (temp != nullptr)
        {
            ++len;
            temp = temp->next;
        }
        return len;
    }
    int getKthFromLast(Node *head, int k)
    {
        int len = length(head);
        if (k > len)
            return -1;
        Node *temp = head;
        for (int i = 0; i < len - k; i++)
            temp = temp->next;
        return temp->data;
    }
};