#include <iostream>
using namespace std;
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
private:
    Node *reverseNode(Node *head)
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
    Node *removeLeadingZeros(Node *head)
    {
        while (head != nullptr && head->data == 0)
        {
            head = head->next;
        }
        return head;
    }

public:
    Node *addOne(Node *head)
    {
        head = removeLeadingZeros(head);
        head = reverseNode(head);
        Node *curr = head;
        int carry = 1;
        while (curr != nullptr)
        {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;

            if (carry == 0)
                break;

            if (curr->next == nullptr && carry != 0)
            {
                curr->next = new Node(0);
            }
            curr = curr->next;
        }
        if (carry != 0)
        {
            curr->next = new Node(carry);
        }

        head = reverseNode(head);
        return head;
    }
};
int main()
{
    Solution sol;
    Node *head1 = new Node(4);
    head1->next = new Node(5);
    head1->next->next = new Node(6);
    Node *ans = sol.addOne(head1);
    while (ans != nullptr)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}
