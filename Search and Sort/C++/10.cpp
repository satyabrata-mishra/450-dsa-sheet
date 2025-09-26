#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &arr, int target)
    {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];
                    if (sum == target)
                    {
                        ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                        while (left < right && arr[left] == arr[left + 1])
                            left++;
                        while (left < right && arr[right] == arr[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                    else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {0, 0, 2, 1, 1};
    vector<vector<int>> ans = sol.fourSum(arr, 3);
    for (vector<int> i : ans)
    {
        for (int j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "New Answer: \n";
    arr = {10, 2, 3, 4, 5, 7, 8};
    ans = sol.fourSum(arr, 23);
    for (vector<int> i : ans)
    {
        for (int j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "New Answer: \n";
    arr = {0, 0, 2, 1, 1};
    ans = sol.fourSum(arr, 2);
    for (vector<int> i : ans)
    {
        for (int j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "New Answer: \n";
    return 0;
}
