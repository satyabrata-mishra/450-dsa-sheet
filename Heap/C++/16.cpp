#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    string rearrangeString(string s)
    {
        unordered_map<char, int> map;
        for (char i : s)
            map[i]++;
        priority_queue<pair<int, char>> q;
        for (pair<char, int> i : map)
            q.push({i.second, i.first});
        string ans = "";
        while (q.size() > 1)
        {
            pair<int, char> p1 = q.top();
            q.pop();
            pair<int, char> p2 = q.top();
            q.pop();
            p1.first--;
            p2.first--;
            ans += p1.second;
            ans += p2.second;
            if (p1.first > 0)
                q.push(p1);
            if (p2.first > 0)
                q.push(p2);
        }
        if (q.size() == 0)
            return ans;
        if (q.top().first > 1)
            return "";
        return ans + q.top().second;
    }
};
int main()
{
    Solution sol;
    cout << sol.rearrangeString("aaabc") << "\n";
    cout << sol.rearrangeString("aaabb") << "\n";
    cout << sol.rearrangeString("aaaabc") << "\n";
    return 0;
}
