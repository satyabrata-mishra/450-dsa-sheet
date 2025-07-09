#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        int i = 0, j = arr.size() - 1;
        while (i < j)
        {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
};
int main()
{
    Solution sol;
    vector<int> myArray = {1, 4, 3, 2, 6, 5, 7};
    sol.reverseArray(myArray);
    for (int num : myArray)
    {
        cout << num << " ";
    }
    return 0;
}