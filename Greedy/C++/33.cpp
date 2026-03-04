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
        unordered_map<char, int> freq;
        for (char i : s)
        {
            ++freq[i];
        }
        priority_queue<pair<int, char>> maxHeap;
        for (pair<char, int> p : freq)
        {
            maxHeap.push({p.second, p.first});
        }
        string ans = "";
        while (maxHeap.size() >= 2)
        {
            pair<int, char> curr1 = maxHeap.top();
            maxHeap.pop();
            pair<int, char> curr2 = maxHeap.top();
            maxHeap.pop();
            ans += curr1.second;
            ans += curr2.second;
            --curr1.first;
            --curr2.first;
            if (curr1.first != 0)
            {
                maxHeap.push(curr1);
            }
            if (curr2.first != 0)
            {
                maxHeap.push(curr2);
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
        ans += maxHeap.top().second;
        return ans;
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
