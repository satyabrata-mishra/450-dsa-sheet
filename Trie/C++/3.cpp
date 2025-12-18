#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
    Node *link[26];
    bool isLast;
    vector<int> index;

public:
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            link[i] = nullptr;
            isLast = false;
        }
    }
    bool containsKey(char c)
    {
        return link[c - 'a'] != nullptr;
    }
    void setLink(char c, Node *node)
    {
        link[c - 'a'] = node;
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
    void setIndex(int ind)
    {
        index.push_back(ind);
    }
    vector<int> getIndex()
    {
        return index;
    }
};
class Solution
{
private:
    Node *root;
    void insert(string str, int index)
    {
        Node *dummy = root;
        for (char i : str)
        {
            if (!dummy->containsKey(i))
            {
                dummy->setLink(i, new Node());
            }
            dummy = dummy->getLink(i);
        }
        dummy->setisLast();
        dummy->setIndex(index);
    }
    void collect(Node *root, vector<string> &arr, vector<vector<string>> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->getisLast())
        {
            vector<string> temp;
            for (int i : root->getIndex())
            {
                temp.push_back(arr[i]);
            }
            ans.push_back(temp);
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->getLink('a' + i) != nullptr)
            {
                collect(root->getLink('a' + i), arr, ans);
            }
        }
    }

public:
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        root = new Node();
        vector<string> tempArr = arr;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            sort(tempArr[i].begin(), tempArr[i].end());
            insert(tempArr[i], i);
        }
        vector<vector<string>> ans;
        collect(root, arr, ans);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> ans = sol.anagrams(arr);
    for (vector<string> i : ans)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    arr = {"no", "on", "is"};
    ans = sol.anagrams(arr);
    for (vector<string> i : ans)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    arr = {"listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"};
    ans = sol.anagrams(arr);
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
