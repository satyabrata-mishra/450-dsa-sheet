#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        int aInd = a.size() - 1, bInd = 0, bLen = b.size();
        while (aInd >= 0 && bInd < b.size())
        {
            if (a[aInd] > b[bInd])
            {
                swap(a[aInd], b[bInd]);
                --aInd;
                ++bInd;
            }
            else
            {
                break;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};
int main()
{
    vector<int> a = {2, 4, 7, 10}, b = {2, 3};
    Solution sol;
    sol.mergeArrays(a, b);
    for (int i : a)
    {
        cout << i << " ";
    }
    for (int i : b)
    {
        cout << i << " ";
    }
    return 0;
}
