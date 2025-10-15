#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int n)
    {
        data = n;
        left = right = nullptr;
    }
};
class Solution
{
private:
    void levelOrderTraversal(Node *root, unordered_map<int, vector<int>> &map, int &level)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *temp = q.front();
                q.pop();
                map[level].push_back(temp->data);
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
            ++level;
        }
    }
    unordered_map<int, int> frequencyCalculator(vector<int> &list)
    {
        unordered_map<int, int> freq;
        for (int i : list)
        {
            ++freq[i];
        }
        return freq;
    }
    bool mapCompare(unordered_map<int, int> map1, unordered_map<int, int> map2)
    {
        if (map1.size() != map2.size())
        {
            return false;
        }
        for (auto i : map1)
        {
            auto temp = map2.find(i.first);
            if (temp == map2.end() || temp->second != i.second)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        unordered_map<int, vector<int>> map1, map2;
        int level1 = 1, level2 = 1;
        levelOrderTraversal(root1, map1, level1);
        levelOrderTraversal(root2, map2, level2);
        if (level1 != level2)
        {
            return false;
        }
        for (int i = 1; i <= level1; i++)
        {
            unordered_map<int, int> tempFreqMap1 = frequencyCalculator(map1[i]);
            unordered_map<int, int> tempFreqMap2 = frequencyCalculator(map2[i]);
            if (!mapCompare(tempFreqMap1, tempFreqMap2))
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    Node *root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->right->left = new Node(5);
    root1->right->right = new Node(4);
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    cout << sol.areAnagrams(root1, root2);
    return 0;
}
