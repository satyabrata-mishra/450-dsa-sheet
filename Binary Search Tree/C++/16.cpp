#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
class Solution
{
private:
    Node *insert(Node *root, int key, int &succ)
    {
        if (!root)
            return new Node(key);

        if (key < root->data)
        {
            succ = root->data; // current node could be successor
            root->left = insert(root->left, key, succ);
        }
        else
        {
            root->right = insert(root->right, key, succ);
        }

        return root;
    }

public:
    vector<int> findLeastGreater(vector<int> &arr, int n)
    {
        vector<int> result;
        // set<int> bst;
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     auto upperBound = bst.upper_bound(arr[i]);
        //     if (upperBound != bst.end())
        //     {
        //         result.push_back(*upperBound);
        //     }
        //     else
        //     {
        //         result.push_back(-1);
        //     }
        //     bst.insert(arr[i]);
        // }
        Node *root = NULL;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i)
        {
            int succ = -1;
            root = insert(root, arr[i], succ);
            result.push_back(succ);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    arr = sol.findLeastGreater(arr, arr.size());
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {2, 6, 9, 1, 3, 2};
    arr = sol.findLeastGreater(arr, arr.size());
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
