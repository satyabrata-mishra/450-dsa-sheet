#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
private:
    void dfs(int cRow, int row, vector<vector<string>> &list, vector<vector<string>> &ans, vector<string> &sentence)
    {
        if (cRow == row)
        {
            ans.push_back(sentence);
            return;
        }
        for (int cCol = 0; cCol < list[cRow].size(); cCol++)
        {
            sentence.push_back(list[cRow][cCol]);
            dfs(cRow + 1, row, list, ans, sentence);
            sentence.pop_back();
        }
    }

public:
    vector<vector<string>> sentences(vector<vector<string>> &list)
    {
        int row = list.size();
        vector<vector<string>> ans;
        vector<string> sentence;
        dfs(0, row, list, ans, sentence);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> list = {{"you", "we"}, {"have", "are"}, {"sleep", "eat", "drink"}};
    list = sol.sentences(list);
    for (vector<string> i : list)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
