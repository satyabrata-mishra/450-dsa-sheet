#include <vector>
using namespace std;
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
void inorderTraversal(Node *root, vector<int> &nodes)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->data);
    inorderTraversal(root->right, nodes);
}
float findMedian(struct Node *root)
{
    vector<int> nodes;
    inorderTraversal(root, nodes);

    int n = nodes.size();
    if (n % 2 != 0)
        return nodes[n / 2];
    else
        return (nodes[n / 2 - 1] + nodes[n / 2]) / 2.0f;
}
int main()
{
    return 0;
}
