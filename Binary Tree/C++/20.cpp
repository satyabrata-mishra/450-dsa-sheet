#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
private:
    void inorderTraversal(vector<int> &arr, vector<int> &inorder, int i, int n)
    {
        if (i >= n)
        {
            return;
        }
        inorderTraversal(arr, inorder, 2 * i + 1, n);
        inorder.push_back(arr[i]);
        inorderTraversal(arr, inorder, 2 * i + 2, n);
    }

public:
    int minSwaps(vector<int> arr)
    {
        int n = arr.size();
        vector<int> inorder;
        inorderTraversal(arr, inorder, 0, n);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({inorder[i], i});
        }
        sort(v.begin(), v.end());
        int noOfSwaps = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].second != i)
            {
                swap(v[v[i].second], v[i]);
                ++noOfSwaps;
                --i;
            }
        }
        return noOfSwaps;
    }
};
int main()
{
    Solution sol;
    cout << sol.minSwaps({5, 6, 7, 8, 9, 10, 11}) << "\n"; // 3
    cout << sol.minSwaps({1, 2, 3}) << "\n";               // 1
    return 0;
}
