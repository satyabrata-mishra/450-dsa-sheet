#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string str = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] == last[i])
            {
                str += first[i];
            }
            else
            {
                break;
            }
        }
        return str;
    }
};
int main()
{
    Solution sol;
    vector<string> arr = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(arr) << "\n";
    arr = {"dog", "racecar", "car"};
    cout << sol.longestCommonPrefix(arr) << "\n";
    return 0;
}
