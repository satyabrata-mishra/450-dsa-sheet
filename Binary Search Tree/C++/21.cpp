#include <vector>
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
    void inorder(Node *root, vector<int> &list)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, list);
        list.push_back(root->data);
        inorder(root->right, list);
    }
    Node *flattenBST(Node *root)
    {
        vector<int> list;
        inorder(root, list);
        Node *ans = new Node(list[0]);
        Node *dummy = ans;
        for (int i = 1; i < list.size(); i++)
        {
            dummy->right = new Node(list[i]);
            dummy = dummy->right;
        }
        return ans;
    }
};