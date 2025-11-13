#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        if (arr.size() >= 1 && arr[0] == 0)
        {
            return -1;
        }
        int maxReach = arr[0], jumps = 1, steps = arr[0], n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return jumps;
            }
            maxReach = max(maxReach, i + arr[i]);
            --steps;
            if (steps == 0)
            {
                jumps++;
                if (i >= maxReach)
                {
                    return -1;
                }
                steps = maxReach - i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << sol.minJumps(arr) << "\n";
    arr = {1, 4, 3, 2, 6, 7};
    cout << sol.minJumps(arr) << "\n";
    arr = {0, 10, 20};
    cout << sol.minJumps(arr) << "\n";
    return 0;
}
