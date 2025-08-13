#include <iostream>
#include <vector>
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
    TreeNode *buildTree(TreeNode *root, int x)
    {
        if (root == nullptr)
        {
            root = new TreeNode(x);
            return root;
        }
        if (root->val < x)
            root->right = buildTree(root->right, x);
        else
            root->left = buildTree(root->left, x);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = nullptr;
        for (int i : preorder)
            root = buildTree(root, i);
        return root;
    }
};
int main()
{
    return 0;
}
