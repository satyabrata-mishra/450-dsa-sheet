#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
class Solution
{
public:
    void inorder(Node *root, priority_queue<int> &q)
    {
        if (root == nullptr)
            return;
        inorder(root->left, q);
        q.push(root->data);
        inorder(root->right, q);
    }
    void builtTree(Node *root, priority_queue<int> &q)
    {
        if (root == nullptr)
            return;
        builtTree(root->right, q);
        root->data = q.top();
        q.pop();
        builtTree(root->left, q);
    }
    Node *binaryTreeToBST(Node *root)
    {
        priority_queue<int> q;
        inorder(root, q);
        builtTree(root, q);
        return root;
    }
};
int main()
{
    return 0;
}
