#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n - 1) / 2];
        vector<pair<int, int>> list;
        for (int i : arr)
            list.push_back({abs(i - m), i});
        sort(list.begin(), list.end(), [](const pair<int, int> a, const pair<int, int> b)
             { if(a.first == b.first)
                    return a.second > b.second;
                return a.first > b.first; });
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            ans.push_back(list[i].second);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {6, 7, 11, 7, 6, 8};
    int k = 5;
    arr = sol.getStrongest(arr, k);
    for (int i : arr)
        cout << i << " ";
    return 0;
}
