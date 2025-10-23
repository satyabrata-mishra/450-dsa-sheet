#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    void backtrack(string &s, int currentIndex, int noOfParts, string ip, vector<string> &res)
    {
        if (noOfParts == 4 && currentIndex == s.size())
        {
            res.push_back(ip.substr(0, ip.size() - 1));
            return;
        }
        if (noOfParts >= 4 || currentIndex >= s.size())
        {
            return;
        }
        for (int length = 1; length <= 3 && currentIndex + length <= s.size(); length++)
        {
            string segment = s.substr(currentIndex, length);
            if ((segment[0] == '0' && segment.size() > 1) || stoi(segment) > 255)
            {
                continue;
            }
            backtrack(s, currentIndex + length, noOfParts + 1, ip + segment + '.', res);
        }
    }
    vector<string> generateIp(string s)
    {
        vector<string> result;
        backtrack(s, 0, 0, "", result);
        return result;
    }
};
int main()
{
    Solution sol;
    string str = "255678166";
    vector<string> ans = sol.generateIp(str);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    str = "25505011535";
    ans = sol.generateIp(str);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
