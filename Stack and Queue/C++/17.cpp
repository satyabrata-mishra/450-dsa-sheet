#include <string>
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    int maxLen(string &s)
    {
        stack<int> stack;
        stack.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else
            {
                stack.pop();
                if (stack.empty())
                {
                    stack.push(i);
                }
                else
                {
                    maxLen = max(maxLen, i - stack.top());
                }
            }
        }
        return maxLen;
    }
};
int main()
{
    Solution sol;
    string str = "(()(";
    cout << sol.maxLen(str) << "\n";
    str = "()(())(";
    cout << sol.maxLen(str) << "\n";
    str = "(()())";
    cout << sol.maxLen(str) << "\n";
    return 0;
}
