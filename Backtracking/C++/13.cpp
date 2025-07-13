#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
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
    string str = "ABC";
    Solution sol;
    vector<string> ans = sol.findPermutation(str);
    for (string i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
