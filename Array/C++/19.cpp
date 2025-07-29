#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void rightRotate(vector<int> &arr, int start, int end)
    {
        int temp = arr[end];
        for (int i = end; i > start; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[start] = temp;
    }

    void rearrange(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if ((i % 2 == 0 && arr[i] < 0) || (i % 2 != 0 && arr[i] >= 0))
            {
                int j = i + 1;
                while (j < n)
                {
                    if ((i % 2 == 0 && arr[j] >= 0) || (i % 2 != 0 && arr[j] < 0))
                    {
                        break;
                    }
                    j++;
                }

                // If no such element, break
                if (j == n)
                    break;
                rightRotate(arr, i, j);
            }
        }
    }
};

int main()
{
    vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    Solution sol;
    sol.rearrange(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
