#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(int n, int m, vector<int> &x, vector<int> &y)
    {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int h = 1, v = 1;
        int i = m - 2, j = n - 2;
        int cost = 0;

        while (i >= 0 && j >= 0)
        {
            if (x[i] >= y[j])
            {
                cost += x[i] * h;
                v++;
                i--;
            }
            else
            {
                cost += y[j] * v;
                h++;
                j--;
            }
        }

        while (i >= 0)
        {
            cost += x[i] * h;
            i--;
        }

        while (j >= 0)
        {
            cost += y[j] * v;
            j--;
        }

        return cost;
    }
};

int main()
{
    Solution obj;

    vector<int> x1 = {2, 1, 3, 1, 4};
    vector<int> y1 = {4, 1, 2};
    cout << obj.minCost(4, 6, x1, y1) << endl; // Output: 42

    vector<int> x2 = {1, 1, 1};
    vector<int> y2 = {1, 1, 1};
    cout << obj.minCost(4, 4, x2, y2) << endl; // Output: 15

    return 0;
}