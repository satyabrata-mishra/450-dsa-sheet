#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void threeWayPartition(vector<int> &arr, int a, int b)
    {
        int n = arr.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (arr[mid] < a)
            {
                swap(arr[low], arr[mid]);
                ++low;
                ++mid;
            }
            else if (arr[mid] > b)
            {
                swap(arr[mid], arr[high]);
                --high;
            }
            else
            {
                ++mid;
            }
        }
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 3, 4};
    int a = 1, b = 2;
    sol.threeWayPartition(arr, a, b);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {1, 4, 3, 6, 2, 1};
    a = 1, b = 3;
    sol.threeWayPartition(arr, a, b);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
