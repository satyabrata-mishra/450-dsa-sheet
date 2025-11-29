#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<string>> sentences(vector<vector<string>> &list)
    {
        vector<vector<string>> ans;
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> list = {{"you", "we"}, {"have", "are"}};
    list = sol.sentences(list);
    for (vector<string> i : list)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
