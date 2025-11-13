#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    Node *divide(Node *head)
    {
        Node *evenStart = new Node(0), *oddStart = new Node(0);
        Node *dummyEven = evenStart, *dummyOdd = oddStart;
        while (head != nullptr)
        {
            if (head->data % 2 == 0)
            {
                dummyEven->next = new Node(head->data);
                dummyEven = dummyEven->next;
            }
            else
            {
                dummyOdd->next = new Node(head->data);
                dummyOdd = dummyOdd->next;
            }
            head = head->next;
        }
        dummyEven->next = oddStart->next;
        return evenStart->next;
    }
};
int main()
{
    Solution sol;
    Node *head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(6);
    head = sol.divide(head);
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
