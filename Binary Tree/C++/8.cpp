#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
class Solution
{
public:
    // Function to return list containing elements of left view of binary tree.
    vector<int> leftView(Node *root)
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> tempList;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *tempNode = q.front();
                q.pop();
                tempList.push_back(tempNode->data);
                if (tempNode->left)
                {
                    q.push(tempNode->left);
                }
                if (tempNode->right)
                {
                    q.push(tempNode->right);
                }
            }
            ans.push_back(tempList[0]);
        }
        return ans;
    }
};
int main()
{
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right = new Node(3);
    Solution sol;
    for (int i : sol.leftView(tree))
    {
        cout << i << " ";
    }
    return 0;
}
