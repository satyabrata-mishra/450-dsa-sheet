#include <vector>
#include <iostream>
#include <algorithm>
#define M 1000000007
#define ll long long int
using namespace std;
class Solution
{
public:
    ll maxValue(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        ll sum = 0;
        for (int i = 0; i < arr.size(); i++)
            sum += (ll)arr[i] * i;
        return sum % M;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << sol.maxValue(arr) << "\n";
    arr = {1, 2, 3};
    cout << sol.maxValue(arr) << "\n";
    return 0;
}
