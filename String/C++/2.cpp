#include <iostream>
#include <unordered_map>
using namespace std;
void printDuplicates(string s)
{
    unordered_map<char, int> count;
    for (char ch : s)
    {
        count[ch]++;
    }
    for (auto c : count)
    {
        if (c.second > 1)
        {
            cout << c.first << "\n";
        }
    }
}

int main()
{
    string s = "geeksforgeeks";
    printDuplicates(s);
    return 0;
}
