#include <map>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = nullptr;
        random = nullptr;
    }
};
class Solution
{
public:
    Node *cloneLinkedList1(Node *head) // SC - O(n)
    {
        map<Node *, Node *> map;
        Node *temp = head;
        while (temp != nullptr)
        {
            map[temp] = new Node(temp->data);
            temp = temp->next;
        }
        for (pair<Node *, Node *> i : map)
        {
            i.second->next = map[i.first->next];
            i.second->random = map[i.first->random];
        }
        return map[head];
    }
    Node *cloneLinkedList2(Node *head) // SC - O(1)
    {
    }
};
int main()
{
    Node *node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);
    node->next->next->next->next = new Node(5);
    node->random = node->next->next;
    node->next->random = node;
    node->next->next->random = node->next->next->next->next;
    node->next->next->next->random = node->next->next;
    node->next->next->next->next->random = node->next;
    Solution sol;
    Node *ans = sol.cloneLinkedList2(node);
    while (ans != nullptr)
    {
        cout << ans->data << " " << ans->random->data << "\n";
        ans = ans->next;
    }
    return 0;
}
