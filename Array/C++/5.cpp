#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        unordered_set<int> unionSet;
        for (int num : a)
            unionSet.insert(num);

        for (int num : b)
            unionSet.insert(num);
        vector<int> result;
        for (int num : unionSet)
            result.push_back(num);
        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> a = {1, 2, 3}, b = {4, 5, 6};
    vector<int> ans = sol.findUnion(a, b);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
