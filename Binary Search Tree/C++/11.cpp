struct Node
{
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
    void length(Node *root, int &len)
    {
        if (root == nullptr)
            return;
        ++len;
        length(root->left, len);
        length(root->right, len);
    }
    void helper(Node *root, int &k, int &ans)
    {
        if (root == nullptr)
            return;
        helper(root->left, k, ans);
        --k;
        if (k == 0)
        {
            ans = root->data;
            return;
        }
        helper(root->right, k, ans);
    }
    int kthLargest(Node *root, int k)
    {
        int len = 0, ans = -1;
        length(root, len);
        int temp = len - k + 1;
        helper(root, temp, ans);
        return ans;
    }
};