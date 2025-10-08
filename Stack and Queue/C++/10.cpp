#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (string token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if (token == "+")
                {
                    st.push(num1 + num2);
                }
                else if (token == "-")
                {
                    st.push(num1 - num2);
                }
                else if (token == "*")
                {
                    st.push(num1 * num2);
                }
                else if (token == "/")
                {
                    st.push(num1 / num2);
                }
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
int main()
{
    Solution sol;
    vector<string> token = {"2", "1", "+", "3", "*"};
    cout << sol.evalRPN(token) << "\n";
    token = {"4", "13", "5", "/", "+"};
    cout << sol.evalRPN(token) << "\n";
    token = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << sol.evalRPN(token) << "\n";
    return 0;
}
