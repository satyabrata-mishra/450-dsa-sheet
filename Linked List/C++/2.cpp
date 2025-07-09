#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Solution
{
public:
    bool detectLoop(Node *head)
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
    node->next->next->next->next->next = node->next->next->next;
    Solution sol;
    cout << sol.detectLoop(node);
    return 0;
}
