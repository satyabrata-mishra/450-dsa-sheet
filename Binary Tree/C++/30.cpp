#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *lca(Node *root, int n1, int n2)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root;
        }
        Node *left = lca(root->left, n1, n2);
        Node *right = lca(root->right, n1, n2);
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        return left ? left : right;
    }
};
int main()
{
    Solution sol;
    Node *root = new Node(11);
    root->left = new Node(22);
    root->left->left = new Node(44);
    root->left->right = new Node(44);
    root->right = new Node(33);
    root->right->left = new Node(66);
    root->right->right = new Node(77);
    Node *ans = sol.lca(root, 77, 22);
    cout << ans->data << " ";
    return 0;
}
