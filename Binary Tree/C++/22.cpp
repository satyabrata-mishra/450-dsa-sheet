#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    bool check(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        pair<bool, int> foundLeafNode = {false, -1};
        int level = 0;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *temp = q.front();
                if (temp->left == nullptr && temp->right == nullptr)
                {
                    if (foundLeafNode.first && foundLeafNode.second != level)
                        return false;
                    if (!foundLeafNode.first)
                        foundLeafNode = {true, level};
                }
                q.pop();
                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
            ++level;
        }
        return true;
    }
};
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(10);
    root->left->right = new Node(15);
    root->right = new Node(30);
    // root->right->left = new Node(20);
    // root->right->right = new Node(30);
    Solution sol;
    cout << sol.check(root);
    return 0;
}
