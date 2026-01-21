#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
private:
    bool topologicalSort(char src, unordered_map<char, vector<char>> &adjacencyList, unordered_map<char, int> &visited, string &ans)
    {
        visited[src] = 1;
        for (char neighbour : adjacencyList[src])
        {
            if (visited[neighbour] == 1)
            {
                return false;
            }
            if (visited[neighbour] == 0)
            {
                if (topologicalSort(neighbour, adjacencyList, visited, ans) == false)
                {
                    return false;
                }
            }
        }
        visited[src] = 2;
        ans += src;
        return true;
    }

public:
    string findOrder(vector<string> words)
    {
        unordered_map<char, vector<char>> adjacencyList;
        unordered_map<char, int> visited;
        unordered_set<char> chars;
        for (string w : words)
            for (char c : w)
                chars.insert(c);
        int n = words.size();
        for (int i = 0; i < n - 1; i++)
        {
            string str1 = words[i], str2 = words[i + 1];
            int len = min(str1.size(), str2.size());
            int ind = 0;
            while (ind < len && str1[ind] == str2[ind])
            {
                ++ind;
            }
            if (ind == len && str1.size() > str2.size())
            {
                return "";
            }
            adjacencyList[str1[ind]].push_back(str2[ind]);
        }
        for (char i : chars)
        {
            visited[i] = 0;
        }
        string ans = "";
        for (char i : chars)
        {
            if (visited[i] == 0)
            {
                if (topologicalSort(i, adjacencyList, visited, ans) == false)
                {
                    return "";
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.findOrder({"baa", "abcd", "abca", "cab", "cad"}) << "\n";              // bdac
    cout << sol.findOrder({"caa", "aaa", "aab"}) << "\n";                              // cab
    cout << sol.findOrder({"ab", "cd", "ef", "ad"}) << "\n";                           // ""
    cout << sol.findOrder({"dddc", "a", "ad", "ab", "b", "be", "cd", "cded"}) << "\n"; // edabc
    return 0;
}
