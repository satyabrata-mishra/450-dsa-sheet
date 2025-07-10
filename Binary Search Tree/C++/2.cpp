struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
class Solution
{
public:
    int minValue(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        };
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root->data;
    }
};