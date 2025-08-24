#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    int length(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            ++len;
            head = head->next;
        }
        return len;
    }
    ListNode *middleNode(ListNode *head)
    {
        int len = length(head);
        for (int i = 0; i < len / 2; i++)
            head = head->next;
        return head;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    Solution sol;
    ListNode *ans = sol.middleNode(head);
    while (ans != nullptr)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}
