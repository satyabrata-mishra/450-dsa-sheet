#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> boyerMooreAlgo(string str, string pattern)
{
    vector<int> ans;
    int i = 0, j = pattern.size();
    while (j <= str.size())
    {
        string temp = str.substr(i, j - i);
        if (temp.compare(pattern) == 0)
        {
            ans.push_back(i);
        }
        ++i;
        ++j;
    }
    return ans;
}
int main()
{
    string str = "AABAACAADAABAABA";
    string pattern = "AABA";
    vector<int> ans = boyerMooreAlgo(str, pattern);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
