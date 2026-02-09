#include <iostream>
#include <unordered_map>
using namespace std;
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
    Node(char data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class Solution
{
private:
    string postorderTraversal(Node *root, unordered_map<string, int> &mp, int &count)
    {
        if (root == nullptr)
        {
            return "#";
        }
        string left = postorderTraversal(root->left, mp, count);
        string right = postorderTraversal(root->right, mp, count);
        string subtree = to_string(root->data) + "," + left + "," + right;
        if (left == "#" && right == "#")
        {
            return subtree;
        }
        if (mp[subtree] == 1)
        {
            ++count;
        }
        mp[subtree]++;
        return subtree;
    }

public:
    int dupSub(Node *root)
    {
        unordered_map<string, int> mp;
        int count = 0;
        postorderTraversal(root, mp, count);
        return (count == 0 ? 0 : 1);
    }
};
int main()
{
    Node *root = new Node('1');
    root->left = new Node('2');
    root->left->left = new Node('4');
    root->left->right = new Node('5');

    root->right = new Node('3');
    root->right->right = new Node('2');
    root->right->right->left = new Node('4');
    root->right->right->right = new Node('5');
    Solution sol;
    cout << sol.dupSub(root) << "\n";
    return 0;
}
