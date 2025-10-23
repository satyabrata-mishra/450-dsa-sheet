#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
void inorderTraversal(Node *root, vector<int> &inorderArr)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left, inorderArr);
    inorderArr.push_back(root->data);
    inorderTraversal(root->right, inorderArr);
}
void preorderFill(Node *root, vector<int> &inorderArr, int &index)
{
    if (root == nullptr)
    {
        return;
    }
    root->data = inorderArr[index++];
    preorderFill(root->left, inorderArr, index);
    preorderFill(root->right, inorderArr, index);
}
void convertBSTtoMinHeap(Node *root)
{
    vector<int> inorderArr;
    inorderTraversal(root, inorderArr);
    int index = 0;
    preorderFill(root, inorderArr, index);
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    convertBSTtoMinHeap(root);
    return 0;
}
