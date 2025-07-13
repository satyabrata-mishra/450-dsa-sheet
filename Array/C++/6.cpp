#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    void rotateByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        k %= n;
        if (k == 0)
        {
            return;
        }
        int index = 0;
        for (int i = n - k; i < n; i++)
        {
            ans[index++] = nums[i];
        }
        for (int i = 0; i < n - k; i++)
        {
            ans[index++] = nums[i];
        }
        nums = ans;
    }

public:
    void rotate(vector<int> &arr)
    {
        rotateByK(arr, 1);
    }
};
int main()
{
    Solution sol;
    vector<int> list = {1, 2};
    sol.rotate(list);
    for (int i : list)
    {
        cout << i << " ";
    }
    return 0;
}
