#include <stdlib.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
};
class Solution
{
public:
    Node *buildTree(Node *root, int x)
    {
        if (root == nullptr)
        {
            return newNode(x);
        }
        if (root->data > x)
            root->left = buildTree(root->left, x);
        else
            root->right = buildTree(root->right, x);
        return root;
    }
    Node *Bst(int pre[], int size)
    {
        Node *root = nullptr;
        for (int i = 0; i < size; i++)
            root = buildTree(root, pre[i]);
        return root;
    }
};
int main()
{
    return 0;
}
