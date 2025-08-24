#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    int findStepKeyIndex(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        int i = 0;
        while (i < n)
        {
            if (arr[i] == x)
                return i;
            int jump = max(1, (int)abs(arr[i] - x) / k);
            i += jump;
        }
        return -1;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {4, 5, 6, 7, 6};
    cout << sol.findStepKeyIndex(arr, 1, 6) << "\n";
    arr = {20, 40, 50};
    cout << sol.findStepKeyIndex(arr, 20, 70) << "\n";
    return 0;
}
