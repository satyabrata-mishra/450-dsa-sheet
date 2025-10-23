#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void convertMinToMaxHeap(vector<int> &arr, int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }
    void heapify(vector<int> &arr, int n, int i)
    {
        int parent = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[parent] < arr[left])
        {
            parent = left;
        }
        if (right < n && arr[parent] < arr[right])
        {
            parent = right;
        }
        if (parent != i)
        {
            swap(arr[i], arr[parent]);
            heapify(arr, n, parent);
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    sol.convertMinToMaxHeap(arr, arr.size());
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {3, 4, 8, 11, 13};
    sol.convertMinToMaxHeap(arr, arr.size());
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
