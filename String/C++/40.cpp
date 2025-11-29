#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
private:
    bool isAnagram(string &a, string &b)
    {
        if (a.size() != b.size())
        {
            return false;
        }
        vector<int> freq(256, 0);
        for (char i : a)
        {
            freq[i]++;
        }
        for (char i : b)
        {
            freq[i]--;
        }
        for (int i = 0; i < 256; i++)
        {
            if (freq[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

public:
    int transform(string a, string b)
    {
        if (!isAnagram(a, b))
        {
            return -1;
        }
        int aLen = a.size(), bLen = b.size();
        int ans = 0, i = aLen - 1, j = bLen - 1;
        while (i >= 0 && j >= 0)
        {
            if (a[i] == b[j])
            {
                --i;
                --j;
            }
            else
            {
                ++ans;
                --i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.transform("abd", "bad") << "\n";                       // 1
    cout << sol.transform("GeeksForGeeks", "ForGeeksGeeks") << "\n";   // 3
    cout << sol.transform("abcd", "efgh") << "\n";                     // -1
    cout << sol.transform("YUZKxQReJATCsD", "seCJQKZRTADUxY") << "\n"; // 13
    return 0;
}
