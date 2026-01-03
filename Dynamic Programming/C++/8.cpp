#include <iostream>
using namespace std;
class Solution
{
public:
    int countFriendsPairings(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        int a = 1, b = 1;
        for (int i = 2; i <= n; i++)
        {
            int temp = b + ((i - 1) * a);
            a = b;
            b = temp;
        }
        return b;
    }
};
int main()
{
    Solution sol;
    cout << sol.countFriendsPairings(1) << "\n"; // 1
    cout << sol.countFriendsPairings(2) << "\n"; // 2
    cout << sol.countFriendsPairings(3) << "\n"; // 4
    cout << sol.countFriendsPairings(4) << "\n"; // 10
    return 0;
}
