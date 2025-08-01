#include <iostream>
using namespace std;
class Solution
{
public:
    int findPosition(int n)
    {
        int count_of_1 = 0;
        int position = -1, cnt = 1;
        while (n > 0)
        {
            if (n & 1)
            {
                count_of_1++;
                position = cnt;
            }

            if (count_of_1 == 2)
                return -1;

            n = n >> 1;
            cnt++;
        }
        return position;
    }
};
int main()
{

    Solution sol;
    cout << sol.findPosition(2) << "\n";
    cout << sol.findPosition(5) << "\n";
    return 0;
}
