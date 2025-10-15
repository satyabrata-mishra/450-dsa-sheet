#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    bool validateOp(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), j = 0;
        stack<int> stack;
        for (int i = 0; i < n; i++)
        {
            stack.push(a[i]);
            while (!stack.empty() && stack.top() == b[j])
            {
                ++j;
                stack.pop();
            }
        }
        return stack.empty();
    }
};
int main()
{
    Solution sol;
    vector<int> a = {1, 2, 3}, b = {2, 1, 3};
    cout << sol.validateOp(a, b) << "\n";
    a = {1, 2, 3}, b = {3, 1, 2};
    cout << sol.validateOp(a, b) << "\n";
    return 0;
}
