#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string findLargest(vector<int> &arr)
    {
        vector<string> strArr;
        for (int i : arr)
            strArr.push_back(to_string(i));
        sort(strArr.begin(), strArr.end(), [](const string &a, const string &b)
             { return (b + a) < (a + b); });
        string ans = "";
        for (string i : strArr)
            ans += i;
        return ans[0] == '0' ? "0" : ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {54, 546, 548, 60};
    cout << sol.findLargest(arr) << "\n";
    arr = {3, 30, 34, 5, 9};
    cout << sol.findLargest(arr) << "\n";
    arr = {3, 4, 6, 5, 9};
    cout << sol.findLargest(arr) << "\n";
    return 0;
}
