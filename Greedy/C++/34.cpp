#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxEqualSum(int n1, int n2, int n3, vector<int> s1, vector<int> s2, vector<int> s3)
    {
        int i = 0, j = 0, k = 0, sum1 = 0, sum2 = 0, sum3 = 0;
        for (int i : s1)
        {
            sum1 += i;
        }
        for (int i : s2)
        {
            sum2 += i;
        }
        for (int i : s3)
        {
            sum3 += i;
        }
        while (i < n1 && j < n2 && k < n3)
        {
            if (sum1 == sum2 && sum2 == sum3)
            {
                return sum1;
            }
            else if (sum1 > min(sum2, sum3))
                sum1 -= s1[i++];
            else if (sum2 > min(sum1, sum3))
                sum2 -= s2[j++];
            else if (sum3 > min(sum2, sum1))
                sum3 -= s3[k++];
        }
        return 0;
    }
};
int main()
{
    Solution sol;
    cout << sol.maxEqualSum(3, 4, 2, {4, 2, 3}, {1, 1, 2, 3}, {1, 4}) << "\n";
    cout << sol.maxEqualSum(2, 1, 3, {4, 7}, {10}, {1, 2, 3}) << "\n";
    return 0;
}
