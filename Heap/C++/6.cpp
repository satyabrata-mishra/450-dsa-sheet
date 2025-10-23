#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int> c;
        for (int i : a)
        {
            c.push_back(i);
        }
        for (int i : b)
        {
            c.push_back(i);
        }
        int size = n + m;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(c, size, i);
        }
        return c;
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
        if (i != parent)
        {
            swap(arr[i], arr[parent]);
            heapify(arr, n, parent);
        }
    }
};
int main()
{
    Solution sol;
    vector<int> a = {10, 5, 6, 2}, b = {12, 7, 9};
    vector<int> ans = sol.mergeHeaps(a, b, a.size(), b.size());
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}
