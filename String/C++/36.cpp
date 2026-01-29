#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int findSubString(string str)
    {
        int n = str.length();
        unordered_set<char> distinct(str.begin(), str.end());
        int required = distinct.size();
        unordered_map<char, int> freq;
        int formed = 0, left = 0, ans = INT32_MAX;
        for (int right = 0; right < n; right++)
        {
            freq[str[right]]++;
            if (freq[str[right]] == 1)
                formed++;
            while (formed == required)
            {
                ans = min(ans, right - left + 1);
                freq[str[left]]--;
                if (freq[str[left]] == 0)
                    formed--;
                left++;
            }
        }
        return (ans == INT32_MAX ? 0 : ans);
    }
};
int main()
{
    Solution sol;
    cout << sol.findSubString("aabcbcdbca") << "\n";    // 4
    cout << sol.findSubString("aaab") << "\n";          // 2
    cout << sol.findSubString("geeksforgeeks") << "\n"; // 7
    return 0;
}
