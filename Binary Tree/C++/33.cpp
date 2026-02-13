#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
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
    string postorder(Node *root, unordered_map<string, int> &mp, vector<Node *> &ans)
    {
        if (root == nullptr)
        {
            return "#";
        }
        string left = postorder(root->left, mp, ans);
        string right = postorder(root->right, mp, ans);
        string curr = to_string(root->data) + "," + left + "," + right;
        if (mp[curr] == 1)
        {
            ans.push_back(root);
        }
        mp[curr]++;
        return curr;
    }

public:
    vector<Node *> printAllDups(Node *root)
    {
        vector<Node *> ans;
        unordered_map<string, int> mp;
        postorder(root, mp, ans);
        return ans;
    }
};
void display(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);

    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);

    root->right->right = new Node(4);
    Solution sol;
    vector<Node *> ans = sol.printAllDups(root);
    for (Node *i : ans)
    {
        display(i);
        cout << "\n";
    }
    return 0;
}
