#include <iostream>
#include <vector>
#include <string>
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
    void insert(string str)
    {
        Node *dummy = root;
        for (char c : str)
        {
            if (!dummy->getLink(c))
            {
                dummy->setLink(c, new Node());
            }
            dummy = dummy->getLink(c);
        }
        dummy->setisLast();
    }
    void dfs(Node *node, string &prefix, vector<string> &ans)
    {
        if (node->getisLast())
        {
            ans.push_back(prefix);
        }
        for (int i = 0; i < 26; i++)
        {
            if (node->getLink(i + 'a') != nullptr)
            {
                prefix.push_back(i + 'a');
                dfs(node->getLink(i + 'a'), prefix, ans);
                prefix.pop_back();
            }
        }
    }

public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        root = new Node();
        int sLen = s.length();
        for (int i = 0; i < n; i++)
        {
            insert(contact[i]);
        }
        vector<vector<string>> ans;
        Node *dummy = root;
        string prefix = "";
        for (char c : s)
        {
            prefix.push_back(c);
            if (dummy == nullptr || dummy->containsKey(c) == false)
            {
                ans.push_back({"0"});
                dummy = nullptr;
            }
            else
            {
                dummy = dummy->getLink(c);
                vector<string> temp;
                dfs(dummy, prefix, temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    int n = 3;
    string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    string s = "geeips";
    vector<vector<string>> ans = sol.displayContacts(n, contact, s);
    for (vector<string> i : ans)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
