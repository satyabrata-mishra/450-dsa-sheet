#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

class Solution
{
private:
    unordered_map<int, int> bracketMapping;
    void mapping(string &str)
    {
        stack<int> stack;
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                stack.push(i);
            }
            else if (str[i] == ')')
            {
                bracketMapping[stack.top()] = i;
                stack.pop();
            }
        }
    }
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    Node *rec(string &str, int si, int ei)
    {
        if (si > ei)
        {
            return nullptr;
        }
        int num1 = 0;
        while (si < str.length() && isDigit(str[si]))
        {
            num1 = (num1 * 10) + (str[si] - '0');
            si++;
        }
        si--;
        Node *root = new Node(num1);
        int closingBracket = -1;
        if (si + 1 <= ei && str[si + 1] == '(')
        {
            closingBracket = bracketMapping[si + 1];
        }
        if (closingBracket != -1)
        {
            root->left = rec(str, si + 2, closingBracket - 1);
            root->right = rec(str, closingBracket + 2, ei - 1);
        }
        return root;
    }

public:
    Node *treeFromString(string str)
    {
        mapping(str);
        return rec(str, 0, str.size() - 1);
    }
};
void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main()
{
    Solution sol;
    Node *ans = sol.treeFromString("4(2(3)(1))(6(5))");
    inorderTraversal(ans);
    return 0;
}
