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

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
private:
    void preorderTraversal(Node *root, int target, int sum, unordered_map<int, int> &mp, int &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        sum += root->data;
        if (sum == target)
        {
            ++ans;
        }
        ans += mp[sum - target];
        mp[sum]++;
        preorderTraversal(root->left, target, sum, mp, ans);
        preorderTraversal(root->right, target, sum, mp, ans);
        mp[sum]--;
    };

public:
    int countAllPaths(Node *root, int k)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        preorderTraversal(root, k, 0, mp, ans);
        return ans;
    }
};
int main()
{
    Node *root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(2);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);
    Solution sol;
    cout << sol.countAllPaths(root, 7) << "\n";
    return 0;
}
