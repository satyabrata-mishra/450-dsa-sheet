struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class Solution
{
private:
    int helper(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        int oldValue = root->data;
        root->data = left + right;
        return left + right + oldValue;
    }

public:
    void toSumTree(Node *node)
    {
        helper(node);
    }
};
int main()
{
    return 0;
}
