#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
class Solution
{
public:
    void inorderTraversal(Node *root, vector<Node *> &list)
    {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, list);
        list.push_back(root);
        inorderTraversal(root->right, list);
    }
    void populateNext(Node *root)
    {
        vector<Node *> list;
        inorderTraversal(root, list);
        int n = list.size();
        for (int i = 0; i < n; i++)
            list[i]->next = list[i + 1];
    }
};
int main()
{
    Solution sol;
    Node *node = new Node(10);
    node->left = new Node(8);
    node->left->left = new Node(3);
    node->right = new Node(12);
    sol.populateNext(node);
    return 0;
}
