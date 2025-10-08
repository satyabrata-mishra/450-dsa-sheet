#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            else if (root->left == nullptr)
            {
                return root->right;
            }
            else if (root->right == nullptr)
            {
                return root->left;
            }
            else
            {
                TreeNode *successor = findMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
                return root;
            }
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
    TreeNode *findMin(TreeNode *root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }
};
void preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    preorderTraversal(root->left);
    cout << root->val << " ";
    preorderTraversal(root->right);
}
int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root = sol.deleteNode(root, 3);
    preorderTraversal(root);
    return 0;
}
