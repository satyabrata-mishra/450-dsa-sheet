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
private:
    void display(Node *head)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

private:
    Node *reverse(Node *head)
    {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Step 2: Reverse second half
        Node *secondHalf = reverse(slow->next);
        // Step 3: Compare halves
        Node *firstHalf = head, *temp = secondHalf;
        while (temp)
        {
            if (firstHalf->data != temp->data)
            {
                return false;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        return true;
    }
};
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);
    // head->next->next->next->next->next->next = new Node(3);
    Solution sol;
    cout << sol.isPalindrome(head);
    return 0;
}
