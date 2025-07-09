#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string &s)
    {
        string temp = s;
        reverse(s.begin(), s.end());
        cout << s << "\n";
        return temp.compare(s) == 0;
    }
};
int main()
{
    Solution sol;
    string str = "abba";
    cout << sol.isPalindrome(str) << "\n";
    str = "abc";
    cout << sol.isPalindrome(str) << "\n";
    return 0;
}
