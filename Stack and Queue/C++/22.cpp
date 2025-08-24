#include <stack>
using namespace std;
class StackQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int);
    int pop();
};
void StackQueue::push(int B)
{
    s1.push(B);
}

int StackQueue::pop()
{
    if (s1.empty())
        return -1;
    while (s1.size() > 1)
    {
        s2.push(s1.top());
        s1.pop();
    }
    int ans = s1.top();
    s1.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    return ans;
}