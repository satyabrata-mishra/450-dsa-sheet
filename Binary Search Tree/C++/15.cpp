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
    void inorder(Node *root, int &l, int &h, int &ans)
    {
        if (root == nullptr)
            return;
        inorder(root->left, l, h, ans);
        if (root->data >= l && root->data <= h)
            ++ans;
        inorder(root->right, l, h, ans);
    }
    int getCount(Node *root, int l, int h)
    {
        int ans = 0;
        inorder(root, l, h, ans);
        return ans;
    }
};
int main()
{
    return 0;
}
