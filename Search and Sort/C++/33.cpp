#include <vector>
#include <iostream>
using namespace std;
class Solution
{
private:
    void mergeSort(vector<int> &arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k++] = L[i++];
            }
            else
            {
                arr[k++] = R[j++];
            }
        }
        while (i < n1)
        {
            arr[k++] = L[i++];
        }
        while (j < n2)
        {
            arr[k++] = R[j++];
        }
    }
    void mergeSortHelper(vector<int> &arr, int left, int right)
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        mergeSort(arr, left, mid, right);
    }

public:
    int inversionCount(vector<int> arr)
    {
        int ans = 0;
        mergeSortHelper(arr, 0, arr.size());
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.inversionCount({2, 4, 1, 3, 5}) << "\n"; // 3
    cout << sol.inversionCount({2, 3, 4, 5, 6}) << "\n"; // 0
    cout << sol.inversionCount({10, 10, 10}) << "\n";    // 0
    return 0;
}
