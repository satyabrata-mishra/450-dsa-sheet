#include <iostream>
using namespace std;

// Definition for singly-linked list
struct Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

class Solution
{
private:
    int getLength(Node *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            ++len;
            head = head->next;
        }
        return len;
    }

public:
    Node *intersectPoint(Node *head1, Node *head2)
    {
        int len1 = getLength(head1);
        int len2 = getLength(head2);

        // Align both pointers to the same start point
        while (len1 > len2)
        {
            head1 = head1->next;
            len1--;
        }

        while (len2 > len1)
        {
            head2 = head2->next;
            len2--;
        }

        // Traverse both lists and find intersection
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1 == head2)
                return head1;
            head1 = head1->next;
            head2 = head2->next;
        }

        return nullptr;
    }
};

int main()
{
    // Shared part of the list
    Node *intersection = new Node(8);
    intersection->next = new Node(4);
    intersection->next->next = new Node(5);

    // First list: 4 -> 1 -> [8 -> 4 -> 5]
    Node *head1 = new Node(4);
    head1->next = new Node(1);
    head1->next->next = intersection;

    // Second list: 5 -> 6 -> 1 -> [8 -> 4 -> 5]
    Node *head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(1);
    head2->next->next->next = intersection;

    Solution sol;
    Node *result = sol.intersectPoint(head1, head2);

    if (result != nullptr)
        cout << "Intersection at node with data: " << result->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
