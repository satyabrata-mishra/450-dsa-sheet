#include <vector>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
class Solution
{
public:
    Node *merge2List(Node *n1, Node *n2)
    {
        Node *ans = new Node(0);
        Node *dummy = ans;
        while (n1 != nullptr && n2 != nullptr)
        {
            if (n1->data <= n2->data)
            {
                dummy->next = new Node(n1->data);
                n1 = n1->next;
            }
            else if (n1->data > n2->data)
            {
                dummy->next = new Node(n2->data);
                n2 = n2->next;
            }
            dummy = dummy->next;
        }
        while (n1 != nullptr)
        {
            dummy->next = new Node(n1->data);
            dummy = dummy->next;
            n1 = n1->next;
        }
        while (n2 != nullptr)
        {
            dummy->next = new Node(n2->data);
            dummy = dummy->next;
            n2 = n2->next;
        }
        return ans->next;
    }

public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        if (arr.size() == 1)
            return arr[0];
        Node *ans = merge2List(arr[0], arr[1]);
        for (int i = 2; i < arr.size(); i++)
        {
            ans = merge2List(ans, arr[i]);
        }
        return ans;
    }
};
int main()
{
    vector<Node *> list;
    Node *n1 = new Node(1);
    n1->next = new Node(2);
    n1->next->next = new Node(3);
    list.push_back(n1);
    n1 = new Node(4);
    n1->next = new Node(5);
    list.push_back(n1);
    n1 = new Node(5);
    n1->next = new Node(6);
    list.push_back(n1);
    n1 = new Node(7);
    n1->next = new Node(8);
    list.push_back(n1);
    Solution sol;
    n1 = sol.mergeKLists(list);
    while (n1 != nullptr)
    {
        cout << n1->data << " ";
        n1 = n1->next;
    }

    return 0;
}
