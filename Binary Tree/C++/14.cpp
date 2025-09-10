#include <vector>
#include <map>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
class Solution
{
public:
    void preorder(Node *root, int diagonal, map<int, vector<int>> &map)
    {
        if (root == nullptr)
            return;
        map[diagonal].push_back(root->data);
        preorder(root->left, diagonal + 1, map);
        preorder(root->right, diagonal, map);
    }
    vector<int> diagonal(Node *root)
    {
        map<int, vector<int>> map;
        preorder(root, 0, map);
        vector<int> ans;
        for (auto i : map)
            for (int j : i.second)
                ans.push_back(j);
        return ans;
    }
};
int main()
{
    return 0;
}
