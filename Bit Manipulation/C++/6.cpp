#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
private:
    string intToBinary(int n)
    {
        string ans = "";
        while (n != 0)
        {
            ans += to_string(n % 2);
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    };

public:
    int setSetBit(int x, int y, int l, int r)
    {
        string binX = intToBinary(x), binY = intToBinary(y);
        int lenX = binX.length(), lenY = binY.length();
        for (int i = 0; i < 32 - lenX; i++)
        {
            binX = "0" + binX;
        }
        for (int i = 0; i < 32 - lenY; i++)
        {
            binY = "0" + binY;
        }
        int index = 31;
        for (int p = l; p <= r; p++)
        {
            int idx = 32 - p;
            if (binY[idx] == '1')
            {
                binX[idx] = '1';
            }
        }
        return stoi(binX, nullptr, 2);
    }
};
int main()
{
    Solution sol;
    cout << sol.setSetBit(44, 3, 1, 5) << "\n";  // 47
    cout << sol.setSetBit(16, 2, 1, 3) << "\n";  // 18
    cout << sol.setSetBit(3, 9, 11, 27) << "\n"; // 3
    return 0;
}
