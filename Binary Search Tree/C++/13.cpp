#include <unordered_set>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
class Solution
{
public:
    void inorder(Node *root, unordered_set<int> &set)
    {
        if (root == nullptr)
            return;
        inorder(root->left, set);
        set.insert(root->data);
        inorder(root->right, set);
    }
    int countPairs(Node *root1, Node *root2, int x)
    {
        unordered_set<int> set1;
        inorder(root1, set1);
        unordered_set<int> set2;
        inorder(root2, set2);
        int ans = 0;
        for (int i : set1)
        {
            int target = x - i;
            if (set2.find(target) != set2.end())
                ++ans;
        }
        return ans;
    }
};
int main()
{
    return 0;
}
