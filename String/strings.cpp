#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    string str = "I am a boy. I am 22 year old.";
    string str1 = "Hello world";
    cout << str << "\n";
    cout << "Length of the string is " << str.size() << "\n";
    cout << str[3] << "\n";
    // Input a string
    // getline(cin, str);
    // cout << str;
    // reverse(str.begin(), str.end());
    cout << str << "\n";
    str.append(str1);
    cout << str << "\n";
    cout << str.compare(str1) << "\n";
    cout << str.substr(2, 6) << "\n";
    s = strtok(str, " ");
    while (s)
    {
        cout << s << "\n";
        s = strtok(0, str);
    }
    return 0;
}