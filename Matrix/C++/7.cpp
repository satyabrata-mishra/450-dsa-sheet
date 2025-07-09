#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = i + 1; j < mat[0].size(); j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    for (int i = 0; i < mat.size(); i++)
    {
        int left = 0, right = mat[0].size() - 1;
        while (left < right)
        {
            int temp = mat[i][left];
            mat[i][left] = mat[i][right];
            mat[i][right] = temp;
            ++left;
            --right;
        }
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(mat);
    for (vector<int> i : mat)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
