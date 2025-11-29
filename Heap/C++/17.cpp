#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string minSum(vector<int> &arr)
    {
        string ans = "";
        int carry = 0;
        priority_queue<int> pq(arr.begin(), arr.end());
        while (!pq.empty())
        {
            int d1 = pq.top(), d2 = 0;
            pq.pop();
            if (!pq.empty())
            {
                d2 = pq.top();
                pq.pop();
            }

            int sum = d1 + d2 + carry;
            carry = sum / 10;
            ans += to_string(sum % 10);
        }
        if (carry != 0)
        {
            ans += to_string(carry);
        }
        reverse(ans.begin(), ans.end());
        int pos = ans.find_first_not_of("0");
        ans.erase(0, pos);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {6, 8, 4, 5, 2, 3}; // 604
    cout << sol.minSum(arr) << "\n";
    arr = {5, 3, 0, 7, 4}; // 82
    cout << sol.minSum(arr) << "\n";
    arr = {9, 4}; // 13
    cout << sol.minSum(arr) << "\n";
    return 0;
}
