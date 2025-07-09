#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
private:
    void helper(unordered_set<string> &set, string str, int index)
    {
        if (str.size() == index)
        {
            set.insert(str);
            return;
        }
        for (int i = index; i < str.size(); i++)
        {
            swap(str[i], str[index]);
            helper(set, str, index + 1);
            swap(str[i], str[index]);
        }
    }

public:
    vector<string> findPermutation(string &s)
    {
        vector<string> ans;
        unordered_set<string> set;
        helper(set, s, 0);
        for (string i : set)
        {
            ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string str = "abc";
    for (string i : sol.findPermutation(str))
    {
        cout << i << " ";
    }
    return 0;
}
