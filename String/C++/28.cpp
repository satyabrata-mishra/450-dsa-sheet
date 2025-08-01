#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;
string firstRepeatedWord(string set)
{
    unordered_map<string, int> map;
    istringstream stream(set);
    vector<string> tokens;
    string str;
    while (getline(stream, str, ' '))
    {
        tokens.push_back(str);
    }
    for (string i : tokens)
    {
        map[i]++;
        if (map[i] > 1)
        {
            return i;
        }
    }
    return "";
}
int main()
{
    string u = "Ravi had been saying that he had been there";
    string v = "Ravi had been saying that";
    string w = "he had had he";
    cout << firstRepeatedWord(u) << "\n";
    cout << firstRepeatedWord(v) << "\n";
    cout << firstRepeatedWord(w) << "\n";
    return 0;
}
