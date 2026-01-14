#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());
        wordListSet.erase(beginWord);
        while (!q.empty())
        {
            pair<string, int> curr = q.front();
            q.pop();
            if (curr.first == endWord)
            {
                return curr.second;
            }
            for (int i = 0; i < curr.first.size(); i++)
            {
                char original = curr.first[i];
                for (char j = 'a'; j <= 'z'; j++)
                {
                    curr.first[i] = j;
                    if (wordListSet.find(curr.first) != wordListSet.end())
                    {
                        wordListSet.erase(curr.first);
                        q.push({curr.first, curr.second + 1});
                    }
                }
                curr.first[i] = original;
            }
        }
        return 0;
    }
};
int main()
{
    Solution sol;
    cout << sol.ladderLength("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << "\n";                                                              // 5
    cout << sol.ladderLength("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << "\n";                                                                     // 0
    cout << sol.ladderLength("ymain", "oecij", {"ymann", "yycrj", "oecij", "ymcnj", "yzcrj", "yycij", "xecij", "yecij", "ymanj", "yzcnj", "ymain"}) << "\n"; // 0
    return 0;
}
