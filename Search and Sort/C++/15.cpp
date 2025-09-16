#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        int n = arr.size(), mul = 1, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
                mul = mul * arr[i];
            if (arr[i] == 0)
                cnt++;
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                v[i] = mul / arr[i];
            }
            else if (cnt == 1)
            {
                if (arr[i] != 0)
                    v[i] = 0;
                else
                    v[i] = mul;
            }
            else
            {
                v[i] = 0;
            }
        }
        return v;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {10, 3, 5, 6, 2};
    arr = sol.productExceptSelf(arr);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    arr = {12, 0};
    arr = sol.productExceptSelf(arr);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    return 0;
}
