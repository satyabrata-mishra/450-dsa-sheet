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
class solution
{
public:
    long long multiplyTwoLists(Node *first, Node *second)
    {
        long long num1 = 0, num2 = 0, mod = 1000000007;
        while (first != nullptr)
        {
            num1 = ((num1 * 10) + first->data) % mod;
            first = first->next;
        }
        while (second != nullptr)
        {
            num2 = ((num2 * 10) + second->data) % mod;
            second = second->next;
        }
        return (num1 * num2) % mod;
    }
};
int main()
{
    solution sol;
    Node *head1 = new Node(1);
    head1->next = new Node(0);
    head1->next->next = new Node(0);
    Node *head2 = new Node(1);
    head2->next = new Node(0);
    cout << sol.multiplyTwoLists(head1, head2) << "\n";
    return 0;
}
