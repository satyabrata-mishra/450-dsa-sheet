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
    Node *removeDuplicates(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            while (temp->next != nullptr && temp->data == temp->next->data)
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return head;
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
    node->next = new Node(0);
    node->next->next = new Node(0);
    node->next->next->next = new Node(1);
    node->next->next->next->next = new Node(1);
    node->next->next->next->next->next = new Node(2);
    node->next->next->next->next->next->next = new Node(2);
    printList(node);
    Solution sol;
    node = sol.removeDuplicates(node);
    printList(node);
    return 0;
}
