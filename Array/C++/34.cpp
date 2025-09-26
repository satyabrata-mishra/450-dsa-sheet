#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    double medianOf2(vector<int> &a, vector<int> &b)
    {
    }
};
int main()
{
    Solution sol;
    vector<int> a = {-5, 3, 6, 12, 15}, b = {-12, -10, -6, -3, 4};
    cout << sol.medianOf2(a, b) << "\n"; // 0
    a = {2, 3, 5, 7}, b = {10, 12, 14, 16};
    cout << sol.medianOf2(a, b) << "\n"; // 8.5
    a = {-5}, b = {-6};
    cout << sol.medianOf2(a, b) << "\n"; //-5.5
    return 0;
}
