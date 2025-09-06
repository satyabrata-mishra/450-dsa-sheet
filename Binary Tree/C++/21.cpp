#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class Solution
{
public:
    bool f = true;
    int helper(Node *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->data;
        int left = helper(root->left);
        int right = helper(root->right);
        if (root->data != left + right)
            f = false;
        return left + right + root->data;
    }
    bool isSumTree(Node *root)
    {
        f = true;
        helper(root);
        return f;
    }
};
int main()
{
    Solution sol;
    Node *head1 = new Node(3);
    head1->left = new Node(1);
    head1->right = new Node(2);
    Node *head2 = new Node(10);
    head2->left = new Node(20);
    head2->left->left = new Node(10);
    head2->left->right = new Node(10);
    head2->right = new Node(30);
    cout << sol.isSumTree(head1) << "\n";
    cout << sol.isSumTree(head2) << "\n";
    return 0;
}
