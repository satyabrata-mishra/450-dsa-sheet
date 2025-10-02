#include <vector>
#include <iostream>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        vector<int> result;
        deque<int> dq;
        for (int i = 0; i < arr.size(); i++)
        {
            int maxVal = INT32_MIN;
            for (int j = i; j < k; j++)
                maxVal = max(maxVal, arr[j]);
            result.push_back(maxVal);
            ++k;
            ++i;
        }
        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    arr = sol.maxOfSubarrays(arr, 3);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    arr = {5, 1, 3, 4, 2};
    arr = sol.maxOfSubarrays(arr, 1);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    return 0;
}
