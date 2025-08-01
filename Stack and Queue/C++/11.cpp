#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int evaluate(vector<string> &arr)
    {
        stack<string> stack;
        for (string i : arr)
        {
            bool check = i.compare("+") == 0 || i.compare("-") == 0 || i.compare("*") == 0 || i.compare("/") == 0 || i.compare("%") == 0;
            if (!check)
            {
                stack.push(i);
                continue;
            }
            else
            {
                int num1 = stoi(stack.top());
                stack.pop();
                int num2 = stod(stack.top());
                stack.pop();
                if (i.compare("+") == 0)
                    num2 += num1;
                if (i.compare("-") == 0)
                    num2 -= num1;
                if (i.compare("*") == 0)
                    num2 *= num1;
                if (i.compare("/") == 0)
                    num2 /= num1;
                if (i.compare("%") == 0)
                    num2 %= num1;
                stack.push(to_string(num2));
            }
        }
        return stoi(stack.top());
    }
};
int main()
{
    Solution sol;
    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"}; //-4
    cout << sol.evaluate(arr) << "\n";
    arr = {"100", "200", "+", "2", "/", "5", "*", "7", "+"}; // 757
    cout << sol.evaluate(arr) << "\n";
    return 0;
}
