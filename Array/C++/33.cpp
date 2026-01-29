#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int minMovesToMakePalindrome(string s)
    {
        int n = s.size();
        int left = 0, right = n - 1, ans = 0;
        while (left < right)
        {
            int l = left, r = right;
            while (s[l] != s[r])
            {
                --r;
            }
            if (l == r)
            {
                swap(s[r], s[r + 1]);
                ++ans;
                continue;
            }
            else
            {
                while (r < right)
                {
                    swap(s[r], s[r + 1]);
                    ++r;
                    ++ans;
                }
            }
            ++left;
            --right;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.minMovesToMakePalindrome("aabb") << "\n";   // 2
    cout << sol.minMovesToMakePalindrome("letelt") << "\n"; // 2
    return 0;
}
