#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;
class Solution
{
public:
    int solve(int n, string s)
    {
        set<char> gotComputer, alreadyVisited;
        int ans = 0;
        for (char i : s)
        {
            if (gotComputer.find(i) != gotComputer.end())
            {
                gotComputer.erase(i);
            }
            else if (gotComputer.size() < n && gotComputer.find(i) == gotComputer.end() && alreadyVisited.find(i) == alreadyVisited.end())
            {
                gotComputer.insert(i);
            }
            else
            {
                alreadyVisited.insert(i);
            }
        }
        return alreadyVisited.size();
    }
};

int main()
{
    Solution sol;
    cout << sol.solve(3, "GACCBDDBAGEE") << "\n"; // 1
    cout << sol.solve(1, "ABCBAC") << "\n";       // 2
    return 0;
}
