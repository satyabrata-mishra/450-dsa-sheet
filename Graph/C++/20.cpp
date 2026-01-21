#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
private:
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

public:
    int countSpanningTrees(vector<vector<int>> &graph, int n, int m)
    {
        vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));
        for (vector<int> edges : graph)
        {
            adjacencyMatrix[edges[0]][edges[1]] = 1;
            adjacencyMatrix[edges[1]][edges[0]] = 1;
        }
        // Laplacian Matrix (D - AdjacencyMatrix)
        vector<vector<int>> lap(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            int degree = 0;
            for (int j = 0; j < n; j++)
            {
                if (adjacencyMatrix[i][j] == 1)
                {
                    degree++;
                    lap[i][j] = -1;
                }
            }
            lap[i][i] = degree;
        }
        // Remove last row and column (cofactor)
        vector<vector<int>> cofactor(n - 1, vector<int>(n - 1));
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1; j++)
                cofactor[i][j] = lap[i][j];
        return determinantOfMatrix(cofactor, n - 1);
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> graph = {{0, 3}, {0, 1}, {1, 2}, {1, 5}, {3, 4}};
    cout << sol.countSpanningTrees(graph, 6, graph.size()) << "\n"; // 1
    return 0;
}
