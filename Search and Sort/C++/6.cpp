#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size();
        long sum = 0, naturalNos = ((long)n * (n + 1)) / 2;
        unordered_map<int, int> map;
        for (int i : arr)
        {
            map[i]++;
            sum += (long)i;
        };
        for (pair<int, int> i : map)
        {
            if (i.second > 1)
            {
                ans.push_back(i.first);
            }
        }
        ans.push_back(naturalNos - sum + ans[0]);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    arr = sol.findTwoElement(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {1, 3, 3};
    arr = sol.findTwoElement(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
