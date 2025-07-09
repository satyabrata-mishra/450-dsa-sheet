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
    Node *reverseKGroup(Node *head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }
        Node *prev = nullptr, *next = nullptr;
        int count = k;
        while (head != nullptr && count--)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = reverseKGroup(next, k);
        return prev;
    }
};
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
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
    node->next->next->next->next->next->next->next = new Node(7);
    node->next->next->next->next->next->next->next->next = new Node(8);

    cout << "Original list: ";
    printList(node);

    // Reverse list using Solution class
    Solution sol;
    Node *reversed = sol.reverseKGroup(node, 4);

    cout << "Reversed list: ";
    printList(reversed);
    return 0;
}