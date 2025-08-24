#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxSum(vector<int> &arr)
    {
        // code here
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {6, 5, 5, 7, 4};
    cout << sol.findMaxSum(arr) << "\n";
    arr = {1, 5, 3};
    cout << sol.findMaxSum(arr) << "\n";
    arr = {4, 4, 4, 4};
    cout << sol.findMaxSum(arr) << "\n";
    return 0;
}
