#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> valueEqualToIndex(vector<int> &arr)
    {
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i + 1 == arr[i])
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {15, 2, 45, 4, 7};
    arr = sol.valueEqualToIndex(arr);
    for (int i : arr)
    {
        cout << i << "\n";
    }
}
