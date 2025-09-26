#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{

public:
    long long countTriplets(int n, long long sum, long long arr[])
    {
        long long ans = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                long long targetSum = arr[i] + arr[left] + arr[right];
                if (targetSum < sum)
                {
                    ++ans;
                    ++left;
                }
                else if (targetSum >= sum)
                    right--;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    long long arr[] = {5, 1, 3, 4, 7};
    long long sum = 12;
    cout << sol.countTriplets(sizeof(arr) / sizeof(long long), sum, arr); // 2
    return 0;
}
