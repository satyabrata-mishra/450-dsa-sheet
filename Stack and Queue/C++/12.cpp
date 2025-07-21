#include <stack>
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    stack<int> insertAtBottom(stack<int> st, int x)
    {
        stack<int> q;
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!q.empty())
        {
            st.push(q.top());
            q.pop();
        }
        return st;
    }
};
int main()
{
    stack<int> stack;
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.push(8);
    Solution sol;
    stack = sol.insertAtBottom(stack, 2);
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}
