#include <iostream>
#include <vector>
using namespace std;
class Node
{
    Node *link[26];
    int count = 0;
    bool isLast = false;

public:
    Node()
    {
        isLast = false;
        for (int i = 0; i < 26; i++)
            link[i] = nullptr;
    }
    ~Node()
    {
        for (int i = 0; i < 26; i++)
            delete link[i];
    }
    bool containsKey(char ch)
    {
        return link[ch - 'a'] != nullptr;
    }
    void setLink(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
    Node *getLink(char ch)
    {
        return link[ch - 'a'];
    }
    void increaseCount()
    {
        ++count;
    }
    int getCount()
    {
        return count;
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
        for (char i : str)
        {
            if (!dummy->containsKey(i))
            {
                dummy->setLink(i, new Node());
            }
            dummy = dummy->getLink(i);
            dummy->increaseCount();
        }
        dummy->setisLast();
    }
    string search(string str)
    {
        string ans = "";
        Node *dummy = root;
        for (char i : str)
        {
            ans += i;
            dummy = dummy->getLink(i);
            if (dummy->getCount() == 1)
            {
                return ans;
            }
        }
        return ans;
    }

public:
    ~Solution()
    {
        delete root;
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        root = new Node();
        for (int i = 0; i < n; i++)
        {
            insert(arr[i]);
        }
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(search(arr[i]));
        }
        return ans;
    }
};
int main()
{
    Solution sol;

    string arr1[] = {"zebra", "dog", "duck", "dove"};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    vector<string> ans1 = sol.findPrefixes(arr1, n1);
    for (string &i : ans1)
        cout << i << " ";
    cout << "\n";

    string arr2[] = {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    vector<string> ans2 = sol.findPrefixes(arr2, n2);
    for (string &i : ans2)
        cout << i << " ";
    cout << "\n";
}
