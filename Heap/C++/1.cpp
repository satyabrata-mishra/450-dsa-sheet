#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void heapSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
    void heapify(vector<int> &arr, int n, int i)
    {
        int parent = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[left] > arr[parent])
        {
            parent = left;
        }
        if (right < n && arr[right] > arr[parent])
        {
            parent = right;
        }
        if (parent != i)
        {
            swap(arr[parent], arr[i]);
            heapify(arr, n, parent);
        }
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {4, 1, 3, 9, 7};
    sol.heapSort(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {2, 1, 5};
    sol.heapSort(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sol.heapSort(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
