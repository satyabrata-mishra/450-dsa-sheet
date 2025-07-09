#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int distinct(vector<vector<int>> M, int N)
    {
        set<int> first(M[0].begin(), M[0].end());
        for (int i = 1; i < N; i++)
        {
            set<int> current(M[i].begin(), M[i].end());
            set<int> result;
            set_intersection(first.begin(), first.end(),
                             current.begin(), current.end(),
                             inserter(result, result.begin()));
            first = result;
        }

        return first.size();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> arr = {{12, 1, 14, 3, 16},
                               {14, 2, 1, 3, 35},
                               {14, 1, 14, 3, 11},
                               {14, 5, 3, 2, 1},
                               {1, 18, 3, 21, 14}};
    cout << sol.distinct(arr, arr.size()) << endl;
    return 0;
}
