#include <iostream>
#include <vector>
#include <unordered_map>
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
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    unordered_map<int, int> indexMap;
    int preIndex = 0;
    Node *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return nullptr;
        int rootVal = preorder[preIndex++];
        Node *root = new Node(rootVal);
        int mid = indexMap[rootVal];
        root->left = buildTreeHelper(preorder, inorder, inStart, mid - 1);
        root->right = buildTreeHelper(preorder, inorder, mid + 1, inEnd);
        return root;
    }

public:
    Node *buildTree(vector<int> inorder, vector<int> preorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            indexMap[inorder[i]] = i;
        return buildTreeHelper(preorder,inorder,0,n-1);
    }
};
void display(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    cout << head->data << " ";
    display(head->left);
    display(head->right);
}
int main()
{
    Solution sol;
    Node *ans = sol.buildTree({3, 1, 4, 0, 5, 2}, {0, 1, 3, 4, 2, 5});
    display(ans);
    return 0;
}
