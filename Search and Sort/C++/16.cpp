#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, [](int a, int b)
             { return __builtin_popcount(a) > __builtin_popcount(b); });
    }
};
int main()
{
    Solution sol;
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    sol.sortBySetBitCount(arr, sizeof(arr) / sizeof(int));
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    int arr1[] = {1, 2, 3, 4, 5, 6};
    sol.sortBySetBitCount(arr1, sizeof(arr1) / sizeof(int));
    for (int i : arr1)
        cout << i << " ";
    cout << "\n";
    return 0;
}
