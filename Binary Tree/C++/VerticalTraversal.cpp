#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void verticalTraversal(TreeNode *root, vector<tuple<int, int, int>> &list, int hd, int vd)
    {
        if (root == nullptr)
        {
            return;
        }
        list.push_back({root->val, hd, vd});
        verticalTraversal(root->left, list, hd - 1, vd + 1);
        verticalTraversal(root->right, list, hd + 1, vd + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<tuple<int, int, int>> list;
        verticalTraversal(root, list, 0, 0);
        sort(list.begin(), list.end(), [](tuple<int, int, int> a, tuple<int, int, int> b)
             {
            if (get<1>(a) == get<1>(b)) {
				if (get<2>(a) == get<2>(b)) {
					return get<0>(a) < get<0>(b);
				} else {
					return get<2>(a) <get<2>(b);
				}
			}
			return get<1>(a) < get<1>(b); });
        map<int, vector<int>> map;
        for (tuple<int, int, int> i : list)
        {
            map[get<1>(i)].push_back(get<0>(i));
        }
        vector<vector<int>> ans;
        for (pair<int, vector<int>> i : map)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);
    node->right = new TreeNode(3);
    node->right->left = new TreeNode(6);
    node->right->right = new TreeNode(7);
    Solution sol;
    vector<vector<int>> ans = sol.verticalTraversal(node);
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
