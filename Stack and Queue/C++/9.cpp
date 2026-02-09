#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int>> mat)
    {
        int n = mat.size();
        // TC -> O(n^2)
        // SC -> o(n)
        // vector<int> iknow(n, 0), knowMe(n, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i != j && mat[i][j] == 1)
        //         {
        //             ++iknow[i];
        //             ++knowMe[j];
        //         }
        //     }
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     if (iknow[i] == 0 && knowMe[i] == n - 1)
        //     {
        //         return i;
        //     }
        // }
        // return -1;
        // TC -> O(n)
        // SC -> o(1)
        int top = 0, down = n - 1;
        while (top < down)
        {
            if (mat[top][down] == 1)
            {
                ++top;
            }
            else
            {
                --down;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i != top && (mat[top][i] == 1 || mat[i][top] == 0))
            {
                return -1;
            }
        }
        return top;
    }
};
int main()
{
    Solution sol;
    cout << sol.celebrity({{1, 1, 0}, {0, 1, 0}, {0, 1, 1}}) << "\n"; // 1
    cout << sol.celebrity({{1, 1}, {1, 1}}) << "\n";                  // -1
    cout << sol.celebrity({{1}}) << "\n";                             // 0
    return 0;
}
