#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
private:
    int length(ListNode *head)
    {
        ListNode *curr = head;
        int ans = 0;
        while (curr != nullptr)
        {
            curr = curr->next;
            ++ans;
        }
        return ans;
    }

public:
    ListNode *middleNode(ListNode *head)
    {
        int len = length(head);
        ListNode *curr = head;
        for (int i = 0; i < len / 2; i++)
        {
            curr = curr->next;
        }
        return curr;
    }
};
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
};
int main()
{
    ListNode *node = new ListNode(0);
    node->next = new ListNode(1);
    node->next->next = new ListNode(2);
    node->next->next->next = new ListNode(1);
    node->next->next->next->next = new ListNode(0);
    node->next->next->next->next->next = new ListNode(2);
    node->next->next->next->next->next->next = new ListNode(2);
    printList(node);
    Solution sol;
    node = sol.middleNode(node);
    printList(node);
    return 0;
}