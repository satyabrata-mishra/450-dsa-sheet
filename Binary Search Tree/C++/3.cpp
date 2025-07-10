#include <iostream>
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
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
private:
    void inorderTraversal(Node *root, vector<int> *traversal)
    {
        if (root == nullptr)
        {
            return;
        }
        inorderTraversal(root->left, traversal);
        traversal->push_back(root->data);
        inorderTraversal(root->right, traversal);
    }

public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<int> list;
        inorderTraversal(root, &list);
        vector<Node *> ans;
        int n = list.size(), pre = -1, suc = -1;
        for (int i = 0; i < n; i++)
        {
            if (list.at(i) == key)
            {
                if (i == n - 1)
                {
                    pre = list.at(i - 1);
                }
                else if (i == 0)
                {
                    suc = list.at(i + 1);
                }
                else
                {
                    pre = list.at(i - 1);
                    suc = list.at(i + 1);
                }
                break;
            }
        }
        ans.push_back(new Node(pre));
        ans.push_back(new Node(suc));
        return ans;
    }
};
int main()
{
    Node *tree = new Node(8);
    tree->right = new Node(9);
    tree->right->right = new Node(10);
    tree->left = new Node(1);
    tree->left->right = new Node(4);
    tree->left->right->left = new Node(3);
    Solution sol;
    vector<Node *> ans = sol.findPreSuc(tree, 8);
    for (Node *i : ans)
    {
        cout << i->data << " ";
    }
    return 0;
}
