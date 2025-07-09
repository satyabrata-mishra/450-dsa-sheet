#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }
};
int main()
{
    Solution sol;
    vector<char> arr = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(arr);
    for (char i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
