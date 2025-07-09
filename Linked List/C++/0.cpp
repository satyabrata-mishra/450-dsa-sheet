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
    Node *reverseList(struct Node *head)
    {
        Node *prev = nullptr, *next = nullptr;
        while (head != nullptr)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
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
}
int main()
{
    Node *node = new Node(0);
    node->next = new Node(1);
    node->next->next = new Node(2);
    node->next->next->next = new Node(3);

    cout << "Original list: ";
    printList(node);

    // Reverse list using Solution class
    Solution sol;
    Node *reversed = sol.reverseList(node);

    cout << "Reversed list: ";
    printList(reversed);
    return 0;
}
