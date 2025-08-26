#include <vector>
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
private:
    Node *merge(Node *head1, Node *head2)
    {
        Node *ans = new Node(0);
        Node *dummy = ans;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->data < head2->data)
            {
                dummy->next = head1;
                head1 = head1->next;
            }
            else
            {
                dummy->next = head2;
                head2 = head2->next;
            }
            dummy = dummy->next;
        }
        dummy->next = head1 ? head1 : head2;
        return ans->next;
    }

public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        Node *result = arr[0];
        for (int i = 1; i < arr.size(); i++)
            result = merge(result, arr[i]);
        return result;
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
