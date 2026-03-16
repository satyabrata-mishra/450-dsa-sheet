#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Node
{
public:
    int freq;
    char ch;
    Node *left;
    Node *right;

    Node(int f, char c)
    {
        freq = f;
        ch = c;
        left = right = NULL;
    }
};
struct cmp
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};
class Solution
{
private:
    void dfs(Node *root, string code, vector<string> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(code);
        }
        dfs(root->left, code + "0", ans);
        dfs(root->right, code + "1", ans);
    }

public:
    vector<string> huffmanCodes(string s, vector<int> f, int n)
    {
        priority_queue<Node *, vector<Node *>, cmp> minHeap;
        for (int i = 0; i < n; i++)
        {
            minHeap.push(new Node(f[i], s[i]));
        }
        while (minHeap.size() > 1)
        {
            Node *left = minHeap.top();
            minHeap.pop();

            Node *right = minHeap.top();
            minHeap.pop();

            Node *parent = new Node(left->freq + right->freq, '#');
            parent->left = left;
            parent->right = right;

            minHeap.push(parent);
        }
        Node *root = minHeap.top();
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<string> ans = sol.huffmanCodes("abcdef", {5, 9, 12, 13, 16, 45}, 6);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
