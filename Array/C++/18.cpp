#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3)
    {
        vector<int> temp1, ans;
        set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(temp1));
        set_intersection(temp1.begin(), temp1.end(), arr3.begin(), arr3.end(), back_inserter(ans));
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    vector<int> arr1 = {1, 5, 10, 20, 40, 80}, arr2 = {6, 7, 20, 80, 100}, arr3 = {3, 4, 15, 20, 30, 70, 80, 120};
    Solution sol;
    vector<int> ans = sol.commonElements(arr1, arr2, arr3);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
