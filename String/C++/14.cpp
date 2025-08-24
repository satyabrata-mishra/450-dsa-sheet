#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        int breakpoint = -1, n = arr.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                breakpoint = i;
                break;
            }
        }
        if (breakpoint == -1)
        {
            reverse(arr.begin(), arr.end());
            return;
        }
        for (int i = n - 1; i > breakpoint; i--)
        {
            if (arr[i] > arr[breakpoint])
            {
                swap(arr[i], arr[breakpoint]);
                break;
            }
        }
        reverse(arr.begin() + breakpoint + 1, arr.end());
    }
};