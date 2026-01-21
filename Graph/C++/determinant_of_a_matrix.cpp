#include <vector>
#include <iostream>
using namespace std;
class Solution
{
private:
    void cofactor(vector<vector<int>> &matrix, vector<vector<int>> &temp, int r, int c, int n)
    {
        int i = 0, j = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row != r && col != c)
                {
                    temp[i][j] = matrix[row][col];
                    ++j;
                    if (j == n - 1)
                    {
                        j = 0;
                        ++i;
                    }
                }
            }
        }
    }

public:
    int determinantOfMatrix(vector<vector<int>> &matrix, int n)
    {
        int ans = 0;
        if (n == 1)
        {
            return matrix[0][0];
        }
        vector<vector<int>> temp(n, vector<int>(n));
        int sign = 1;
        for (int i = 0; i < n; i++)
        {
            cofactor(matrix, temp, 0, i, n);
            ans += sign * matrix[0][i] * determinantOfMatrix(temp, n - 1);
            sign *= -1;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 0, 2, -1}, {3, 0, 0, 5}, {2, 1, 4, -3}, {1, 0, 5, 0}};
    cout << sol.determinantOfMatrix(matrix, matrix.size()) << "\n"; // 30
    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 10, 9}};
    cout << sol.determinantOfMatrix(matrix, matrix.size()) << "\n"; // 12
    return 0;
}
