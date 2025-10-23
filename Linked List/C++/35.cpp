#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    string firstNonRepeating(string s)
    {
        vector<int> freq(26, 0);
        queue<char> q;
        string ans = "";
        for (char i : s)
        {
            ++freq[i - 'a'];
            if (freq[i - 'a'] == 1)
            {
                q.push(i);
            }
            while (!q.empty() && freq[q.front() - 'a'] != 1)
            {
                q.pop();
            }
            if (q.empty())
            {
                ans += '#';
            }
            else
            {
                ans += q.front();
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.firstNonRepeating("aabc") << "\n";
    cout << sol.firstNonRepeating("bb") << "\n";
    return 0;
}
