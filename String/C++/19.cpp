#include <iostream>
#include <string>
using namespace std;
string printSequence(string s)
{
    string arr[] = {
        "2", "22", "222",
        "3", "33", "333",
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777", "7777",
        "8", "88", "888",
        "9", "99", "999", "9999"};
    int n = s.length();
    string res = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            res += "0";
        else
        {
            int idx = s[i] - 'A';
            res += arr[idx];
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    string str = "GFG";
    cout << printSequence(str) << "\n"; // 43334
    str = "HEY U";
    cout << printSequence(str) << "\n"; // 4433999088
    return 0;
}
