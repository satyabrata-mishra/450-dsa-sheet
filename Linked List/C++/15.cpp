#include <iostream>
#include <vector>
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
    bool isCircular(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Node *node = new Node(0);
    node->next = new Node(1);
    node->next->next = new Node(2);
    node->next->next->next = new Node(3);
    node->next->next->next->next = new Node(4);
    node->next->next->next->next->next = new Node(5);
    node->next->next->next->next->next->next = new Node(6);
    node->next->next->next->next->next->next->next = node;
    Solution sol;
    cout << sol.isCircular(node) << "\n";
    return 0;
}
