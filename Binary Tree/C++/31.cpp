#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class Solution
{
private:
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
    int findDistHelper(Node *root, int target, int dist)
    {
        if (root == nullptr)
            return -1;
        if (root->data == target)
            return dist;
        int left = findDistHelper(root->left, target, dist + 1);
        if (left != -1)
            return left;
        return findDistHelper(root->right, target, dist + 1);
    }

public:
    int findDist(Node *root, int a, int b)
    {
        Node *lowestCommonAncestor = lca(root, a, b);
        return findDistHelper(lowestCommonAncestor, a, 0) + findDistHelper(lowestCommonAncestor, b, 0);
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
    cout << sol.findDist(root, 77, 22) << "\n";
    return 0;
}
