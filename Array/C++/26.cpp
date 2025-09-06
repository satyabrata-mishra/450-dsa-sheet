#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isSubset(vector<int> &a, vector<int> &b)
    {
        if (b.size() > a.size())
            return false;
        unordered_map<int, int> aMap, bMap;
        for (int i : a)
            ++aMap[i];
        for (int i : b)
            ++bMap[i];
        for (pair<int, int> i : bMap)
            if (aMap.find(i.first) == aMap.end() || aMap[i.first] < bMap[i.first])
                return false;
        return true;
    }
};
int main()
{
    Solution sol;
    vector<int> a = {11, 7, 1, 13, 21, 3, 7, 3}, b = {11, 3, 7, 1, 7};
    cout << sol.isSubset(a, b) << "\n"; // 1
    a = {1, 2, 3, 4, 4, 5, 6};
    b = {1, 2, 4};
    cout << sol.isSubset(a, b) << "\n"; // 1
    a = {10, 5, 2, 23, 19};
    b = {19, 5, 3};
    cout << sol.isSubset(a, b) << "\n"; // 0
    a = {1, 2, 2};
    b = {1, 1};
    cout << sol.isSubset(a, b) << "\n"; // 0
    return 0;
}
