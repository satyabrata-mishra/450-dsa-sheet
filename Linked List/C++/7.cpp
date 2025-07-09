#include <iostream>
#include <vector>
#include <unordered_set>
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
    Node *moveToFront(Node *head)
    {
        Node *curr = head;
        while (curr->next->next != nullptr)
        {
            curr = curr->next;
        }
        Node *ans = new Node(curr->next->data);
        ans->next = head;
        curr->next = nullptr;
        return ans;
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
    printList(node);
    Solution sol;
    node = sol.moveToFront(node);
    printList(node);
    return 0;
}