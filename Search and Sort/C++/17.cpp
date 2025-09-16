#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minSwaps(vector<int> &arr)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < arr.size(); i++)
            v.push_back({arr[i], i});
        sort(v.begin(), v.end());
        int i = 0, n = arr.size(), swapped = 0;
        while (i < arr.size())
        {
            if (v[i].second != i)
            {
                swap(v[i], v[v[i].second]);
                swapped++;
            }
            else
                i++;
        }
        return swapped;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {2, 8, 5, 4};
    cout << sol.minSwaps(arr) << "\n";
    arr = {10, 19, 6, 3, 5};
    cout << sol.minSwaps(arr) << "\n";
    arr = {32524, 30965, 30657, 18612, 29956, 15628, 16059, 10826, 23546, 22340};
    cout << sol.minSwaps(arr) << "\n";
    return 0;
}
