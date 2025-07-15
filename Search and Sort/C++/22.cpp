#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int aInd = 0, bInd = 0, aSize = a.size(), bSize = b.size();
        while (aInd < aSize && bInd < bSize)
        {
            if (a[aInd] < b[bInd])
            {
                if (--k == 0)
                    return a[aInd];
                aInd++;
            }
            else
            {
                if (--k == 0)
                    return b[bInd];
                bInd++;
            }
        }
        while (aInd < aSize)
        {
            if (--k == 0)
                return a[aInd];
            aInd++;
        }
        while (bInd < bSize)
        {
            if (--k == 0)
                return b[bInd];
            bInd++;
        }
        return -1;
    }
};
int main()
{
    vector<int> a = {2, 3, 6, 7, 9}, b = {1, 4, 8, 10};
    Solution sol;
    cout << sol.kthElement(a, b, 5) << "\n";
    a = {100, 112, 256, 349, 770};
    b = {72, 86, 113, 119, 265, 445, 892};
    cout << sol.kthElement(a, b, 7) << "\n";
    return 0;
}
