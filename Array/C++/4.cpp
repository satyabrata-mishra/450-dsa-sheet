#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void segregateElements(vector<int> &arr)
    {
        vector<int> ans;
        for (int i : arr)
        {
            if (i >= 0)
            {
                ans.push_back(i);
            }
        }
        for (int i : arr)
        {
            if (i < 0)
            {
                ans.push_back(i);
            }
        }
        arr = ans;
    }
};
int main()
{
    Solution sol;
    vector<int> list = {1, -1, 3, 2, -7, -5, 11, 6};
    sol.segregateElements(list);
    for (int i : list)
    {
        cout << i << " ";
    }
    return 0;
}
