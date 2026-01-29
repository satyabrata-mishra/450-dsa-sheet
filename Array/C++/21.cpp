#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> factorial(int n)
    {
        vector<int> ans;
        ans.push_back(1);
        for (int i = 2; i <= n; i++)
        {
            int carry = 0;
            for (int j = ans.size() - 1; j >= 0; j--)
            {
                int temp = ans[j] * i + carry;
                ans[j] = temp % 10;
                carry = temp / 10;
            }
            while (carry != 0)
            {
                ans.insert(ans.begin(), carry % 10);
                carry /= 10;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> ans = sol.factorial(5);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    ans = sol.factorial(10);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
