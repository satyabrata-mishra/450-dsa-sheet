#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *t = q.front();
                q.pop();
                temp.push_back(t->data);
                if (t->left != nullptr)
                {
                    q.push(t->left);
                }
                if (t->right != nullptr)
                {
                    q.push(t->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    Node *tree = new Node(0);
    tree->left = new Node(1);
    tree->right = new Node(2);
    vector<vector<int>> ans = sol.levelOrder(tree);
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
