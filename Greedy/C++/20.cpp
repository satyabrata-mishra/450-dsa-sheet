#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        sort(bt.begin(), bt.end());
        int time = 0, n = bt.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = bt[i];
            time += bt[i];
            bt[i] = time;
            bt[i] -= temp;
            sum += bt[i];
        }
        return sum / n;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {4, 3, 7, 1, 2};
    cout << sol.solve(arr) << "\n";
    arr = {1, 2, 3, 4};
    cout << sol.solve(arr) << "\n";
    return 0;
}
