#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
        : data(0), left(nullptr), right(nullptr) {}

    Node(int x)
        : data(x), left(nullptr), right(nullptr) {}
};
class Solution
{
private:
    void inorderTraversal(Node *root, vector<int> &list)
    {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, list);
        list.push_back(root->data);
        inorderTraversal(root->right, list);
    }

public:
    Node *bToDLL(Node *root)
    {
        vector<int> list;
        inorderTraversal(root, list);
        int n = list.size();
        if (n == 0)
        {
            return nullptr;
        }
        Node *ans = new Node(list[0]);
        ans->left = nullptr;
        Node *dummy = ans;
        for (int i = 1; i < n; i++)
        {
            dummy->right = new Node(list[i]);
            dummy->right->left = dummy;
            dummy = dummy->right;
        }
        return ans;
    }
};
int main()
{
    Node *root = new Node(10);
    root->left = new Node(12);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right = new Node(15);
    root->right->left = new Node(36);
    Solution sol;
    root = sol.bToDLL(root);
    return 0;
}
