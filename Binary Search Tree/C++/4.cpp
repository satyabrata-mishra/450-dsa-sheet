#include <iostream>
#include <climits>
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
        left = right = nullptr;
    }
};
class Solution
{
public:
    bool isBSTUtil(Node *node, long minVal, long maxVal)
    {
        if (node == nullptr)
            return true;

        if (node->data <= minVal || node->data >= maxVal)
            return false;

        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal);
    }
    bool isBST(Node *root)
    {
        return isBSTUtil(root, LONG_MIN, LONG_MAX);
    }
};