#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    void mergerSort2d(vector<int> &arr, int left, int mid, int right, int &ans)
    {
        int n1 = mid - left + 1, n2 = right - mid;
        vector<int> arr1(n1), arr2(n2);
        for (int i = 0; i < n1; i++)
        {
            arr1[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++)
        {
            arr2[j] = arr[mid + j + 1];
        }
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
            {
                arr[k++] = arr1[i++];
            }
            else
            {
                ans += n1 - i;
                arr[k++] = arr2[j++];
            }
        }
        while (i < n1)
        {
            arr[k++] = arr1[i++];
        }
        while (j < n2)
        {
            arr[k++] = arr2[j++];
        }
    }
    void mergeSort(vector<int> &arr, int left, int right, int &ans)
    {
        if (left >= right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ans);
        mergeSort(arr, mid + 1, right, ans);
        mergerSort2d(arr, left, mid, right, ans);
    }

public:
    //  i < j and arr[i] > arr[j]
    int inversionCount(vector<int> arr)
    {
        int ans = 0, n = arr.size();
        mergeSort(arr, 0, n - 1, ans);
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
