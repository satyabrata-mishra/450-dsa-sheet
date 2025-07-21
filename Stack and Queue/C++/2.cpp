#include <iostream>
using namespace std;
class twoStacks
{

    int arr[200];
    int stack1 = 100, stack2 = 99;

public:
    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        arr[stack1++] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        arr[stack2--] = x;
    }

    // Function to remove an element from top of the stack1.

    int pop1()
    {
        if (stack1 == 100)
        {
            return -1;
        }
        return arr[--stack1];
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (stack2 == 99)
        {
            return -1;
        }
        return arr[++stack2];
    }
};
int main()
{
    twoStacks ob;
    ob.push1(1);
    ob.push2(2);
    cout << ob.pop1() << "\n";
    ob.push1(3);
    cout << ob.pop1() << "\n";
    cout << ob.pop1() << "\n";
    return 0;
}
