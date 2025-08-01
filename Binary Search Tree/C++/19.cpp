#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    bool isDeadEndUtil(Node *root, int minVal, int maxVal)
    {
        if (root == nullptr)
            return false;
        if (minVal == maxVal)
            return true;
        bool left = isDeadEndUtil(root->left, minVal, root->data - 1);
        bool right = isDeadEndUtil(root->right, root->data + 1, maxVal);
        return left || right;
    }
    bool isDeadEnd(Node *root)
    {
        return isDeadEndUtil(root->left, 1, INT_MAX);
    }
};
int main()
{
    return 0;
}
