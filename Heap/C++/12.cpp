#include <iostream>
#include <queue>
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
public:
    bool isHeap(Node *tree)
    {
        queue<Node *> q;
        q.push(tree);
        bool hasNullAppeared = false;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (curr != nullptr && hasNullAppeared == true)
                {
                    return false;
                }
                if (curr == nullptr)
                {
                    hasNullAppeared = true;
                    continue;
                }
                if (curr->left != nullptr && curr->left->data > curr->data)
                {
                    return false;
                }
                if (curr->right != nullptr && curr->right->data > curr->data)
                {
                    return false;
                }
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}
