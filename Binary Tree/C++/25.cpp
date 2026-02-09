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
    int postorder(Node *root, int &maxValue)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = postorder(root->left, maxValue);
        int right = postorder(root->right, maxValue);
        int currValue = root->data + left + right;
        maxValue = max(maxValue, currValue);
        return currValue;
    }

public:
    int findLargestSubtreeSum(Node *root)
    {
        int maxValue = INT32_MIN;
        postorder(root, maxValue);
        return maxValue;
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
