#include <vector>
#include <iostream>
using namespace std;
class Solution
{

public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        int n = grid.size(), m = grid[0].size(), len = word.length();
        vector<int> delRow = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> delCol = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != word[0])
                {
                    continue;
                }
                for (int dir = 0; dir < 8; ++dir)
                {
                    int r = i, c = j, k = 0;
                    while (k < len)
                    {
                        if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == word[k])
                        {
                            r += delRow[dir];
                            c += delCol[dir];
                            ++k;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (k == len)
                    {
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<char>> grid = {{'a', 'b', 'a', 'b'}, {'a', 'b', 'e', 'b'}, {'e', 'b', 'e', 'b'}};
    vector<vector<int>> ans = sol.searchWord(grid, "abe"); //{{0,0},{0,2},{1,0}}
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    grid = {{'a', 'b', 'c'}, {'d', 'r', 'f'}, {'g', 'h', 'i'}};
    ans = sol.searchWord(grid, "abc"); //{{0,0}}
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
