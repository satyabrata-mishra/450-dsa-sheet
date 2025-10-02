#include <queue>
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        if (q.size() < k)
            return q;
        stack<int> st;
        while (k--)
        {
            st.push(q.front());
            q.pop();
        }
        queue<int> tempQ;
        while (!q.empty())
        {
            tempQ.push(q.front());
            q.pop();
        }
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        while (!tempQ.empty())
        {
            q.push(tempQ.front());
            tempQ.pop();
        }
        return q;
    }
};
int main()
{
    Solution sol;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q = sol.reverseFirstK(q, 3);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
