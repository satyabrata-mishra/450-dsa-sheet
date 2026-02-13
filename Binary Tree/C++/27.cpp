#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class Solution
{
private:
    int postorder(Node *root, int &ans)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = postorder(root->left, ans);
        int right = postorder(root->right, ans);
        int currSum = root->data + left + right;
        ans = max(ans, currSum);
        return currSum;
    }

public:
    int findLargestSubtreeSum(Node *root)
    {
        int ans = INT32_MIN;
        postorder(root, ans);
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    cout << sol.findLargestSubtreeSum(root) << "\n";
    return 0;
}
