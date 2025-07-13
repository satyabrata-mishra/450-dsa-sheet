#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    void bubbleSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

public:
    int kthSmallest(vector<int> &arr, int k)
    {
        bubbleSort(arr);
        return arr[k - 1];
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    cout << sol.kthSmallest(arr, 3);
    return 0;
}
