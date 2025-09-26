#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int platforms = 1, minPlatforms = 1, n = arr.size(), i = 1, j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                ++platforms;
                ++i;
            }
            else
            {
                --platforms;
                ++j;
            }
            minPlatforms = max(minPlatforms, platforms);
        }
        return minPlatforms;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800}, dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << sol.minPlatform(arr, dep) << "\n";
    arr = {900, 1235, 1100}, dep = {1000, 1240, 1200};
    cout << sol.minPlatform(arr, dep) << "\n";
    arr = {1000, 935, 1100}, dep = {1200, 1240, 1130};
    cout << sol.minPlatform(arr, dep) << "\n";
    arr = {1114, 825, 357, 1415, 54}, dep = {1740, 1110, 2238, 1535, 2323};
    cout << sol.minPlatform(arr, dep) << "\n";
    return 0;
}
// 3 1 3 4