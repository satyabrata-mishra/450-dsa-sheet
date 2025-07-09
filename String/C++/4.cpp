#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool areRotations(string &s1, string &s2)
    {
        return (s1 + s1).find(s2) != string::npos;
    }
};
int main()
{
    Solution sol;
    string s1 = "abcd", s2 = "cdab";
    cout << sol.areRotations(s1, s2) << "\n"; // 1
    s1 = "aab";
    s2 = "aba";
    cout << sol.areRotations(s1, s2) << "\n"; // 1
    s1 = "abcd";
    s2 = "acbd";
    cout << sol.areRotations(s1, s2) << "\n"; // 0
    return 0;
}
