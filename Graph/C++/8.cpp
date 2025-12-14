#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int newColor, int iniColor, vector<int> &delRow, vector<int> &delCol)
    {
        ans[row][col] = newColor;
        int rSize = image.size(), cSize = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < rSize && nCol >= 0 && nCol < cSize && image[nRow][nCol] == iniColor && ans[nRow][nCol] != newColor)
            {
                dfs(nRow, nCol, image, ans, newColor, iniColor, delRow, delCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int r = image.size(), c = image[0].size();
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        vector<int> delRow = {-1, 0, 1, 0}, delCol = {0, 1, 0, -1};
        dfs(sr, sc, image, ans, color, iniColor, delRow, delCol);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    image = sol.floodFill(image, sr, sc, color);
    for (vector<int> i : image)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    image = {{0, 0, 0}, {0, 0, 0}};
    sr = 0, sc = 0, color = 0;
    image = sol.floodFill(image, sr, sc, color);
    for (vector<int> i : image)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}
