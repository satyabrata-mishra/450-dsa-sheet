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
        left = right = nullptr;
    }
};
class Solution
{
public:
    int height(Node *node)
    {
        if (node == nullptr)
        {
            return -1;
        }
        return max(height(node->left), height(node->right)) + 1;
    }
};