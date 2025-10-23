#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {2, 1, 3, 4};
    cout << sol.matrixMultiplication(arr) << "\n";
    arr = {1, 2, 3, 4, 3};
    cout << sol.matrixMultiplication(arr) << "\n";
    arr = {3, 4};
    cout << sol.matrixMultiplication(arr) << "\n";
    return 0;
}
