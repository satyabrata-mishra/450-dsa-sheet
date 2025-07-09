#include <iostream>
#include <string>
using namespace std;
void printSubRec(string s, string curr)
{
    if (s.empty())
    {
        cout << curr << "\n";
        return;
    }
    printSubRec(s.substr(1), curr + s[0]);
    printSubRec(s.substr(1), curr);
};
int main()
{
    printSubRec("abc", "");
    return 0;
}
