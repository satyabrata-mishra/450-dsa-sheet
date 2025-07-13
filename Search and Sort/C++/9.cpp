#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool findPair(vector<int> &arr, int x)
    {
        sort(arr.begin(), arr.end());

        int i = 0;
        int j = 1;
        while (j < arr.size())
        {
            int diff = abs(arr[i] - arr[j]);

            if (diff == x)
                return true;
            else if (diff > x)
                i++;
            else
                j++;
            if (i == j)
                j++;
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {5, 20, 3, 2, 5, 80};
    Solution sol;
    cout << sol.findPair(arr, 78) << "\n";
    return 0;
}
