#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int zero = 0, one = 0, two = 0, n = arr.size();
        for (int i : arr)
        {
            if (i == 0)
            {
                ++zero;
            }
            else if (i == 1)
            {
                ++one;
            }
            else
            {
                ++two;
            }
        }
        int index = 0;
        while (zero--)
        {
            arr[index++] = 0;
        }
        while (one--)
        {
            arr[index++] = 1;
        }
        while (two--)
        {
            arr[index++] = 2;
        }
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    sol.sort012(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
