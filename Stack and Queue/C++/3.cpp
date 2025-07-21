#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Solution
{
private:
    void helper(stack<int> &st, int curr, int mid)
    {
        if (curr == mid)
        {
            st.pop();
            return;
        }
        int temp = st.top();
        st.pop();
        helper(st, curr + 1, mid);
        st.push(temp);
    }

public:
    void deleteMid(stack<int> &s)
    {
        int n = s.size();
        helper(s, 0, s.size() / 2);
    }
};
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    Solution sol;
    sol.deleteMid(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
