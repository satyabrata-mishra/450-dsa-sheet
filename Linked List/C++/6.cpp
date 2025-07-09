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
    Node *removeDuplicates(Node *head)
    {
        if (!head)
            return nullptr;

        unordered_set<int> seen;
        Node *curr = head;
        seen.insert(curr->data);

        while (curr->next != nullptr)
        {
            if (seen.find(curr->next->data) != seen.end())
            {
                curr->next = curr->next->next;
            }
            else
            {
                seen.insert(curr->next->data);
                curr = curr->next;
            }
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
    node->next = new Node(1);
    node->next->next = new Node(2);
    node->next->next->next = new Node(1);
    node->next->next->next->next = new Node(0);
    node->next->next->next->next->next = new Node(2);
    node->next->next->next->next->next->next = new Node(2);
    printList(node);
    Solution sol;
    node = sol.removeDuplicates(node);
    printList(node);
    return 0;
}
