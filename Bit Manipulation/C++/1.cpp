#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> singleNum(vector<int> &arr)
    {
        int xor_all = 0;
        for (int i : arr)
            xor_all ^= i;
        int rightMostSetBit = xor_all & -xor_all;
        int x = 0, y = 0;
        for (int i : arr)
        {
            if (i & rightMostSetBit)
                x ^= i;
            else
                y ^= i;
        }
        if (x > y)
            return {y, x};
        return {x, y};
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 2, 1, 4};
    arr = sol.singleNum(arr);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    arr = {2, 1, 3, 2};
    arr = sol.singleNum(arr);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    arr = {2, 1, 3, 3};
    arr = sol.singleNum(arr);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    return 0;
}
