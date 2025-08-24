struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution
{
public:
    Node *sort(Node *head1, Node *head2)
    {
        Node *ans = new Node(0);
        Node *dummy = ans;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->data <= head2->data)
            {
                dummy->bottom = new Node(head1->data);
                head1 = head1->bottom;
            }
            else if (head1->data > head2->data)
            {
                dummy->bottom = new Node(head2->data);
                head2 = head2->bottom;
            }
            dummy = dummy->bottom;
        }
        while (head1 != nullptr)
        {
            dummy->bottom = new Node(head1->data);
            dummy = dummy->bottom;
            head1 = head1->bottom;
        }
        while (head2 != nullptr)
        {
            dummy->bottom = new Node(head2->data);
            dummy = dummy->bottom;
            head2 = head2->bottom;
        }
        return ans->bottom;
    }
    Node *flatten(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->next == nullptr)
            return root;
        Node *ans = sort(root, root->next);
        root = root->next->next;
        while (root != nullptr)
        {
            ans = sort(ans, root);
            root = root->next;
        }
        return ans;
    }
};