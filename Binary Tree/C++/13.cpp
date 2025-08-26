#include <math.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    int height(Node *root, bool &valid)
    {
        if (root == nullptr)
            return 0;
        int l = height(root->left, valid);
        int r = height(root->right, valid);
        if (abs(l - r) > 1)
            valid = false;
        return 1 + max(l, r);
    }
    bool isBalanced(Node *root)
    {
        bool ans = true;
        height(root, ans);
        return ans;
    }
};