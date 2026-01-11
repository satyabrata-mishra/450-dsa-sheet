#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getMinMax(vector<int> &arr)
    {
        int n = arr.size();
        int mini, maxi, i;
        if (n % 2 == 0)
        {
            if (arr[0] < arr[1])
            {
                mini = arr[0];
                maxi = arr[1];
            }
            else
            {
                mini = arr[1];
                maxi = arr[0];
            }
            i = 2;
        }
        else
        {
            mini = maxi = arr[0];
            i = 1;
        }
        while (i < n - 1)
        {
            if (arr[i] < arr[i + 1])
            {
                mini = min(mini, arr[i]);
                maxi = max(maxi, arr[i + 1]);
            }
            else
            {
                mini = min(mini, arr[i + 1]);
                maxi = max(maxi, arr[i]);
            }
            i += 2;
        }
        return {mini, maxi};
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 4, 3, -5, -4, 8, 6};
    arr = sol.getMinMax(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {12, 3, 15, 7, 9};
    arr = sol.getMinMax(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
