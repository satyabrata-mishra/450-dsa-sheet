#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    void insertAtButtom(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        insertAtButtom(st, x);
        st.push(temp);
    }
    void reverse(stack<int> &st)
    {
        if (st.empty())
            return;
        int temp = st.top();
        st.pop();
        reverse(st);
        insertAtButtom(st, temp);
    }
};
int main()
{
    stack<int> st; // = {3,2,1,7,6};
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);
    Solution sol;
    sol.reverse(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
