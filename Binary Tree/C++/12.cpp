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
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> ans;
        queue<Node *> q;
        q.push(root);
        bool toogle = true;
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
            if (toogle)
            {
                for (int i : tempList)
                {
                    ans.push_back(i);
                }
            }
            else
            {
                for (int i = tempList.size() - 1; i >= 0; i--)
                {
                    ans.push_back(tempList[i]);
                }
            }
            toogle = !toogle;
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
    tree->right->left = new Node(6);
    tree->right->right = new Node(7);
    Solution sol;
    for (int i : sol.zigZagTraversal(tree))
    {
        cout << i << " ";
    }
    return 0;
}
