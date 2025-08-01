#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        stack<int> stack;
        int n = arr.size();
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stack.empty() && stack.top() <= arr[i])
                stack.pop();
            if (!stack.empty())
                ans[i] = stack.top();
            stack.push(arr[i]);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 2, 4};
    arr = sol.nextLargerElement(arr);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    arr = {6, 8, 0, 1, 3};
    arr = sol.nextLargerElement(arr);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    arr = {10, 20, 30, 50};
    arr = sol.nextLargerElement(arr);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    arr = {50, 40, 30, 10};
    arr = sol.nextLargerElement(arr);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    return 0;
}
