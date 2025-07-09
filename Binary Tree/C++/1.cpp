#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int n)
    {
        data = n;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    vector<int> reverseLevelOrder(Node *root)
    {
        vector<vector<int>> list;
        vector<int> ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> tempList;
            for (int i = 0; i < n; i++)
            {
                Node *tempNode = q.front();
                q.pop();
                tempList.push_back(tempNode->data);
                if (tempNode->left != nullptr)
                {
                    q.push(tempNode->left);
                }
                if (tempNode->right != nullptr)
                {
                    q.push(tempNode->right);
                }
            }
            list.push_back(tempList);
        }
        for (int i = list.size() - 1; i >= 0; i--)
        {
            for (int j : list.at(i))
            {
                ans.push_back(j);
            }
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
    vector<int> ans = sol.reverseLevelOrder(tree);
    for (int i : ans)
    {
        cout << i << "\n";
    }
    return 0;
}