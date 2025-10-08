#include <iostream>
using namespace std;
class Node
{
public:
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
    void removeLoop(Node *head)
    {
        Node *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr)
            return;
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        while (slow->next != fast)
        {
            slow = slow->next;
        }
        slow->next = nullptr;
    }
};
int main()
{
    return 0;
}
