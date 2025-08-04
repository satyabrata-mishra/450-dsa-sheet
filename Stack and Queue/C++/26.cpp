#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    queue<int> reverseQueue(queue<int> &q)
    {
        if (q.empty())
            return q;
        int front = q.front();
        q.pop();
        reverseQueue(q);
        q.push(front);
        return q;
    }
};
int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    Solution sol;
    q = sol.reverseQueue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
