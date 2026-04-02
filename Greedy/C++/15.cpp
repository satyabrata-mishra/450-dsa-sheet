#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static long long maximizeSum(long long a[], int n, int k)
    {
        sort(a, a + n);
        for (int i = 0; i < n && k > 0; i++)
        {
            if (a[i] < 0)
            {
                a[i] *= -1;
                --k;
            }
        }

        long long sum = 0, mn = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            mn = min(mn, a[i]);
        }
        if (k % 2 == 1)
        {
            sum -= 2 * mn;
        }
        return sum;
    }
};

int main()
{
    long long arr1[] = {1, 2, -3, 4, 5};
    cout << Solution::maximizeSum(arr1, 5, 1) << endl; // 15

    long long arr2[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20};
    cout << Solution::maximizeSum(arr2, 10, 5) << endl; // 68

    return 0;
}