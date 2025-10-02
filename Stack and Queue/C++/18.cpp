#include <string>
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    bool checkRedundancy(string &s)
    {
        stack<int> st;
        for (char i : s)
        {
            if (i != ')')
            {
                st.push(i);
                continue;
            }
            int count = 0;
            while (!st.empty() && st.top() != '(')
            {
                ++count;
                st.pop();
            }
            if (count == 0 || count == 1)
                return true;
            st.pop();
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string str = "((a+b))";
    cout << sol.checkRedundancy(str) << "\n";
    str = "(a+(b)/c)";
    cout << sol.checkRedundancy(str) << "\n";
    str = "(a+b+(c+d))";
    cout << sol.checkRedundancy(str) << "\n";
    return 0;
}
