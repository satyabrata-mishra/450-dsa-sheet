#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Node
{
private:
    Node *link[26];
    bool isLast;

public:
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            link[i] = nullptr;
        }
        isLast = false;
    }
    ~Node()
    {
        for (int i = 0; i < 26; i++)
        {
            delete link[i];
        }
    }
    bool containsKey(char c)
    {
        return link[c - 'a'] != nullptr;
    }
    void setLink(char c, Node *n)
    {
        link[c - 'a'] = n;
    }
    Node *getLink(char c)
    {
        return link[c - 'a'];
    }
    void setisLast()
    {
        isLast = true;
    }
    bool getisLast()
    {
        return isLast;
    }
};
class Solution
{
private:
    Node *root;
    void insert(string &str)
    {
        Node *dummy = root;
        for (char i : str)
        {
            if (dummy->containsKey(i) == false)
            {
                dummy->setLink(i, new Node());
            }
            dummy = dummy->getLink(i);
        }
        dummy->setisLast();
    }
    bool search(string &str)
    {
        Node *dummy = root;
        for (char i : str)
        {
            if (dummy->containsKey(i) == false)
            {
                return false;
            }
            dummy = dummy->getLink(i);
        }
        return dummy->getisLast();
    }
    bool wordBreakUtil(string &str)
    {
        if (str.length() == 0)
        {
            return true;
        }
        for (int i = 1; i <= str.length(); i++)
        {
            string temp1 = str.substr(0, i), temp2 = str.substr(i);
            if (search(temp1) && wordBreakUtil(temp2))
            {
                return true;
            }
        }
        return false;
    }

public:
    // a : given string to search
    // b : vector of available strings

    int wordBreak(string a, vector<string> b)
    {
        root = new Node();
        for (string i : b)
        {
            insert(i);
        }
        return wordBreakUtil(a);
    }
};
int main()
{
    Solution sol;
    cout << sol.wordBreak("ilike", {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"}) << "\n";
    cout << sol.wordBreak("ilikesamsung", {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"}) << "\n";
    return 0;
}
