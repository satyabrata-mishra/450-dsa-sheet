#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string chooseandswap(string str)
    {
        int n = str.size();
        vector<int> last(26, -1);
        vector<bool> visited(26, false);
        for (int i = 0; i < n; i++)
        {
            last[str[i] - 'a'] = i;
        }
        for (int i = 0; i < n; i++)
        {
            visited[str[i] - 'a'] = true;
            for (char j = 'a'; j < str[i]; j++)
            {
                if (!visited[j - 'a'] && last[j - 'a'] > i)
                {
                    char c1 = str[i];
                    char c2 = j;
                    for (int j = 0; j < n; j++)
                    {
                        if (str[j] == c1)
                            str[j] = c2;
                        else if (str[j] == c2)
                            str[j] = c1;
                    }
                    return str;
                }
            }
        }
        return str;
    }
};
int main()
{
    Solution sol;
    cout << sol.chooseandswap("ccad") << "\n"; // aacd
    cout << sol.chooseandswap("abba") << "\n"; // abba
    return 0;
}
