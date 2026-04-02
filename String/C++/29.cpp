#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minimumNumberOfSwaps(string s)
    {
        int open = 0, close = 0, imbalance = 0, swaps = 0;
        for (char c : s)
        {
            if (c == '[')
            {
                ++open;
                if (imbalance > 0)
                {
                    swaps += imbalance;
                    --imbalance;
                }
            }
            else
            {
                ++close;
                if (close > open)
                {
                    imbalance = close - open;
                }
            }
        }
        return swaps;
    }
};
int main()
{
    Solution sol;
    cout << sol.minimumNumberOfSwaps("[]][][") << "\n";     // 2
    cout << sol.minimumNumberOfSwaps("[][]") << "\n";       // 0
    cout << sol.minimumNumberOfSwaps("[[[][][]]]") << "\n"; // 0
    return 0;
}
