#include <string>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
class Solution
{
public:
    string reorganizeString(string s)
    {
        map<char, int> map;
        for (char i : s)
        {
            ++map[i];
        }
        priority_queue<pair<int, char>> maxHeap;
        for (auto i : map)
        {
            maxHeap.push({i.second, i.first});
        }
        string ans;
        while (maxHeap.size() > 1)
        {
            pair<int, char> p1 = maxHeap.top();
            maxHeap.pop();
            pair<int, char> p2 = maxHeap.top();
            maxHeap.pop();
            ans += p1.second;
            ans += p2.second;
            p1.first--;
            p2.first--;
            if (p1.first > 0)
            {
                maxHeap.push(p1);
            }
            if (p2.first > 0)
            {
                maxHeap.push(p2);
            }
        }
        if (maxHeap.size() == 0)
        {
            return ans;
        }
        if (maxHeap.top().first > 1)
        {
            return "";
        }
        return (ans + maxHeap.top().second);
    }
};
int main()
{
    Solution sol;
    cout << sol.reorganizeString("aab");
    cout << sol.reorganizeString("aaab");
    return 0;
}
