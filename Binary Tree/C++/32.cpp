#include <iostream>
#include <unordered_map>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class Solution
{
private:
    void traverse(unordered_map<Node *, Node *> &map, Node *&start, int target, Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        if (target == root->data)
        {
            start = root;
        }
        if (root->left != nullptr)
        {
            map[root->left] = root;
            traverse(map, start, target, root->left);
        }
        if (root->right != nullptr)
        {
            map[root->right] = root;
            traverse(map, start, target, root->right);
        }
    }

public:
    int kthAncestor(Node *root, int k, int node)
    {
        unordered_map<Node *, Node *> map;
        map[root] = nullptr;
        Node *ans;
        traverse(map, ans, node, root);
        while (k-- && ans != nullptr)
        {
            ans = map[ans];
        }
        return (ans != nullptr ? ans->data : -1);
    }
};

int main()
{
    Solution sol;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << sol.kthAncestor(root, 2, 4) << "\n";
    return 0;
}
