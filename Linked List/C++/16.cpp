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
public:
    pair<Node *, Node *> splitList(struct Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *head1 = head;
        Node *head2 = slow->next;
        fast = (fast->next->next == head) ? fast->next : fast;
        fast->next = head2;
        slow->next = head;
        return {head1, head2};
    }
};