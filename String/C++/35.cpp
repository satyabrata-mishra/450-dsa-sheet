#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
private:
    string freqCalc(string &s)
    {
        map<char, int> track;
        for (char i : s)
        {
            track[i]++;
        }
        string key = "";
        for (pair<char, int> i : track)
        {
            key += string(1, i.first) + to_string(i.second);
        }
        return key;
    }

public:
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        map<string, vector<string>> groups;
        for (string &s : arr)
        {
            string key = freqCalc(s);
            groups[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &entry : groups)
        {
            ans.push_back(entry.second);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> ans = sol.anagrams(arr);
    for (vector<string> i : ans)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    arr = {"no", "on", "is"};
    ans = sol.anagrams(arr);
    for (vector<string> i : ans)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    arr = {"listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"};
    ans = sol.anagrams(arr);
    for (vector<string> i : ans)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
