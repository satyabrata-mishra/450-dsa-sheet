#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    queue<int> rearrangeQueue(queue<int> q)
    {
        queue<int> q1;
        int n = q.size();
        for (int i = 0; i < n / 2; i++)
        {
            q1.push(q.front());
            q.pop();
        }
        queue<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans.push(q1.front());
                q1.pop();
            }
            else
            {
                ans.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);
    q.push(1);
    q = sol.rearrangeQueue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
