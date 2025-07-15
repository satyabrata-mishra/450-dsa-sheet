#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isBalanced(string &k)
    {
        stack<char> stack;
        for (char i : k)
        {
            if (i == '(' || i == '{' || i == '[')
            {
                stack.push(i);
                continue;
            }
            if (stack.empty() || (i == ')' && stack.top() != '(') || (i == '}' && stack.top() != '{') || (i == ']' && stack.top() != '['))
            {
                return false;
            }
            stack.pop();
        }
        if (!stack.empty())
        {
            return false;
        }
        return true;
    }
};
int main()
{
    Solution sol;
    string str = "[{()}]";
    cout << sol.isBalanced(str) << "\n"; // 1
    str = "[()()]{}";
    cout << sol.isBalanced(str) << "\n"; // 1
    str = "([]";
    cout << sol.isBalanced(str) << "\n"; // 0
    str = "([{]})";
    cout << sol.isBalanced(str) << "\n"; // 0
    return 0;
}
