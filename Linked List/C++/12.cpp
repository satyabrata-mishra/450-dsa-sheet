#include <iostream>
using namespace std;
class Node
{
public:
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
private:
    Node *mergeSortHelper(Node *root1, Node *root2)
    {
        Node *ans = new Node(0);
        Node *dummy = ans;
        while (root1 != nullptr && root2 != nullptr)
        {
            if (root1->data <= root2->data)
            {
                dummy->next = new Node(root1->data);
                root1 = root1->next;
            }
            else
            {
                dummy->next = new Node(root2->data);
                root2 = root2->next;
            }
            dummy = dummy->next;
        }
        while (root1 != nullptr)
        {
            dummy->next = new Node(root1->data);
            dummy = dummy->next;
            root1 = root1->next;
        }
        while (root2 != nullptr)
        {
            dummy->next = new Node(root2->data);
            dummy = dummy->next;
            root2 = root2->next;
        }
        return ans->next;
    }

public:
    Node *mergeSort(Node *head)
    {
        if (head->next == nullptr)
        {
            return head;
        }
        Node *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *head2 = slow->next;
        slow->next = nullptr;
        Node *left = mergeSort(head);
        Node *right = mergeSort(head2);
        return mergeSortHelper(left, right);
    }
};
int main()
{
    Node *root1 = new Node(40);
    root1->next = new Node(20);
    root1->next->next = new Node(60);
    root1->next->next->next = new Node(10);
    root1->next->next->next->next = new Node(50);
    root1->next->next->next->next->next = new Node(30);
    Solution sol;
    root1 = sol.mergeSort(root1);
    while (root1 != nullptr)
    {
        cout << root1->data << " ";
        root1 = root1->next;
    }
    return 0;
}
