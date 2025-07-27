#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <functional>
using namespace std;
class Solution
{
public:
    string rearrangeString(string &s)
    {
        map<char, int> freq;
        for (char i : s)
        {
            freq[i]++;
        }
        priority_queue<pair<int, char>> pq;
        for (pair<char, int> p : freq)
        {
            pq.push({p.second, p.first});
        }
        string ans = "";
        while (pq.size() > 1)
        {
            pair<int, char> p1 = pq.top();
            pq.pop();
            pair<int, char> p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            p1.first--;
            p2.first--;
            if (p1.first > 0)
            {
                pq.push(p1);
            }
            if (p2.first > 0)
            {
                pq.push(p2);
            }
        }
        if (pq.size() == 0)
        {
            return ans;
        }
        if (pq.top().first > 1)
        {
            return "";
        }
        return ans + pq.top().second;
    }
};
int main()
{
    Solution sol;
    string str = "aaabcbbb";
    cout << sol.rearrangeString(str) << "\n";
    str = "aaabb";
    cout << sol.rearrangeString(str) << "\n";
    str = "aaaabc";
    cout << sol.rearrangeString(str) << "\n";
    return 0;
}
