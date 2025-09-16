#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> maxMeetings(int n, vector<int> &s, vector<int> &f)
    {
        vector<tuple<int, int, int>> list;
        for (int i = 0; i < n; i++)
            list.push_back({i + 1, s[i], f[i]});
        sort(list.begin(), list.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
             { return get<2>(a) < get<2>(b); });
        tuple<int, int, int> temp = list[0];
        vector<int> ans;
        ans.push_back(get<0>(list[0]));
        for (int i = 1; i < n; i++)
        {
            if (get<2>(temp) < get<1>(list[i]))
            {
                ans.push_back(get<0>(list[i]));
                temp = list[i];
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> s = {1, 3, 0, 5, 8, 5}, f = {2, 4, 6, 7, 9, 9};
    vector<int> ans = sol.maxMeetings(s.size(), s, f);
    for (int i : ans)
        cout << i << " ";
    cout << "\n";
    s = {3}, f = {7};
    ans = sol.maxMeetings(s.size(), s, f);
    for (int i : ans)
        cout << i << " ";
    cout << "\n";
    return 0;
}
