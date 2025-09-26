#include <vector>
#include <iostream>
#include <stack>
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
    void inorderRecursive(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        inorderRecursive(root->left, ans);
        ans.push_back(root->val);
        inorderRecursive(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        while (!stack.empty() || curr != nullptr)
        {
            if (curr != nullptr)
            {
                stack.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stack.top();
                stack.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}
