#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    string longestPalindrome(string &s)
    {
        int n = s.size(), maSize = 0;
        string ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                string subString = s.substr(i, j - i);
                if (isPalindrome(subString) && subString.size() > maSize)
                {
                    ans = subString;
                    maSize = subString.size();
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string s = "forgeeksskeegfor";
    cout << sol.longestPalindrome(s) << "\n";
    s = "Geeks";
    cout << sol.longestPalindrome(s) << "\n";
    s = "abc";
    cout << sol.longestPalindrome(s) << "\n";
    s = "jhumixbdbeaqaebvprdpyffypdrpvdbximuhj";
    cout << sol.longestPalindrome(s) << "\n"; // vprdpyffypdrpv
    return 0;
}
