class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
bool search(Node *root, int x)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    if (root->data > x)
    {
        search(root->left, x);
    }
    if (root->data < x)
    {
        search(root->right, x);
    }
}