#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
private:
    Node *buildTree(Node *head, int i)
    {
        if (head == nullptr)
        {
            head = new Node(i);
            return head;
        }
        if (head->data < i)
        {
            head->right = buildTree(head->right, i);
        }
        else
        {
            head->left = buildTree(head->left, i);
        }
        return head;
    }
    void preorderTraversal(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        ans.push_back(root->data);
        preorderTraversal(root->left, ans);
        preorderTraversal(root->right, ans);
    }

public:
    Node *binaryTreeToBST(Node *root)
    {
        vector<int> list;
        preorderTraversal(root, list);
        Node *ans = nullptr;
        for (int i : list)
        {
            ans = buildTree(ans, i);
        }
        return ans;
    }
};
void inorderDisplay(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    inorderDisplay(head->left);
    cout << head->data << " ";
    inorderDisplay(head->right);
}
int main()
{
    Solution sol;
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head = sol.binaryTreeToBST(head);
    inorderDisplay(head);
    return 0;
}
