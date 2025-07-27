#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        queue<pair<int, Node *>> q;
        q.push({0, root});
        map<int, vector<int>> map;
        while (!q.empty())
        {
            pair<int, Node *> temp = q.front();
            q.pop();
            map[temp.first].push_back(temp.second->data);
            if (temp.second->left != nullptr)
            {
                q.push({temp.first - 1, temp.second->left});
            }
            if (temp.second->right != nullptr)
            {
                q.push({temp.first + 1, temp.second->right});
            }
        }
        vector<int> ans;
        for (pair<int, vector<int>> i : map)
        {
            ans.push_back(i.second[i.second.size() - 1]);
        }
        return ans;
    }
};
int main()
{
    Node *node = new Node(1);
    node->left = new Node(2);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    node->right = new Node(3);
    node->right->left = new Node(6);
    node->right->right = new Node(7);
    Solution sol;
    vector<int> ans = sol.bottomView(node);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
