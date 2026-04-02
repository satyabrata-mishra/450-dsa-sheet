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
private:
    Node *getTail(Node *head)
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp;
    }
    Node *partition(Node *head, Node *tail)
    {
        Node *pivot = head;
        Node *curr = head->next, *prev = head;
        while (curr != tail->next)
        {
            if (pivot->data > curr->data)
            {
                swap(prev->next->data, curr->data);
                prev = prev->next;
            }
            curr = curr->next;
        }
        swap(prev->data, pivot->data);
        return prev;
    }
    void solveSort(Node *head, Node *tail)
    {
        if (head == nullptr || tail == nullptr || head == tail)
        {
            return;
        }
        Node *pivot = partition(head, tail);
        solveSort(head, pivot);
        solveSort(pivot->next, tail);
    }

public:
    struct Node *quickSort(struct Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        Node *tail = getTail(head);
        solveSort(head, tail);
        return head;
    }
};
int main()
{
    Node *root = new Node(1);
    root->next = new Node(9);
    root->next->next = new Node(3);
    root->next->next->next = new Node(8);
    Solution sol;
    root = sol.quickSort(root);
    while (root != nullptr)
    {
        cout << root->data << "->";
        root = root->next;
    }
    return 0;
}
