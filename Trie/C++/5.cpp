#include <iostream>
#include <vector>
using namespace std;
class Node
{
private:
    Node *link[2];
    bool isLast;

public:
    Node()
    {
        for (int i = 0; i < 2; i++)
        {
            link[i] = nullptr;
        }
        isLast = false;
    }
    ~Node()
    {
        for (int i = 0; i < 2; i++)
        {
            delete link[i];
        }
    }
    bool containsKey(char c)
    {
        return link[c - '0'] != nullptr;
    }
    void setLink(char c, Node *n)
    {
        link[c - '0'] = n;
    }
    Node *getLink(char c)
    {
        return link[c - '0'];
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
    bool insert(string &s)
    {
        Node *dummy = root;
        for (char c : s)
        {
            if (!dummy->containsKey(c))
            {
                dummy->setLink(c, new Node());
            }
            dummy = dummy->getLink(c);
        }
        if (dummy->getisLast())
        {
            return false;
        }
        dummy->setisLast();
        return true;
    }

public:
    vector<vector<int>> uniqueRow(int m[1000][1000], int row, int col)
    {
        root = new Node();
        vector<vector<int>> ans;
        for (int i = 0; i < row; i++)
        {
            string str = "";
            vector<int> tmp;
            for (int j = 0; j < col; j++)
            {
                str += to_string(m[i][j]);
                tmp.push_back(m[i][j]);
            }
            if (insert(str))
            {
                ans.push_back(tmp);
            }
        }
        delete root;
        root = nullptr;
        return ans;
    }
};
int main()
{
    Solution sol;
    int m[][1000] = {{1, 1, 0, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}};
    vector<vector<int>> ans = sol.uniqueRow(m, 3, 4);
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    int n[][1000] = {{0, 0, 0, 1}, {0, 0, 0, 1}};
    ans = sol.uniqueRow(n, 2, 4);
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
