#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        set<int> set;
        while (head1 != nullptr)
        {
            set.insert(head1->data);
            head1 = head1->next;
        }
        Node *ans = new Node(0);
        Node *dummy = ans;
        while (head2 != nullptr)
        {
            if (set.find(head2->data) != set.end())
            {
                dummy->next = new Node(head2->data);
                dummy = dummy->next;
            }
            head2 = head2->next;
        }
        return ans->next;
    }
};
int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    Solution sol;
    Node *ans = sol.findIntersection(head1, head2);
    while (ans != nullptr)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}
