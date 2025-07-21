#include <stack>
#include <iostream>
using namespace std;
void push(stack<int> &s, int a)
{
    s.push(a);
}

bool isFull(stack<int> &s, int n)
{
    return s.size() == n;
}

bool isEmpty(stack<int> &s)
{
    return s.empty();
}

int pop(stack<int> &s)
{
    int a = s.top();
    s.pop();
    return a;
}

int getMin(stack<int> &s)
{
    int mini = 100001;
    while (!isEmpty(s))
    {
        if (s.top() < mini)
            mini = s.top();
        s.pop();
    }
    return mini;
}
int main()
{
    return 0;
}
