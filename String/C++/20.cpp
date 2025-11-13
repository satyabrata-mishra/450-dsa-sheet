#include <string>
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    int countMinReversals(string s)
    {
        if (s.length() % 2 != 0)
        {
            return -1;
        }
        stack<char> st;
        int ans = 0;
        for (char i : s)
        {
            if (i == '{')
            {
                st.push(i);
                continue;
            }
            if (st.empty())
            {
                ++ans;
                st.push('{');
            }
            else
            {
                st.pop();
            }
        }
        return ans + st.size() / 2;
    }
};
int main()
{
    Solution sol;
    cout << sol.countMinReversals("}{{}}{{{") << "\n";      // 3
    cout << sol.countMinReversals("{{}{{{}{{}}{{") << "\n"; //-1
    return 0;
}
