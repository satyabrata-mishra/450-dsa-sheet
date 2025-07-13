#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    vector<int> mergeSort(vector<int> list1, vector<int> list2)
    {
        int n1 = list1.size(), n2 = list2.size(), i = 0, j = 0;
        vector<int> ans;
        while (i < n1 && j < n2)
        {
            if (list1[i] <= list2[j])
            {
                ans.push_back(list1[i++]);
            }
            else
            {
                ans.push_back(list2[j++]);
            }
        }
        while (i < n1)
        {
            ans.push_back(list1[i++]);
        }
        while (j < n2)
        {
            ans.push_back(list2[j++]);
        }
        return ans;
    }

public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int n = arr.size();

        if (n == 1)
        {
            return arr[0];
        }
        vector<int> ans = mergeSort(arr[0], arr[1]);
        for (int i = 2; i < n; i++)
        {
            ans = mergeSort(ans, arr[i]);
        }
        return ans;
    }
};
void display(vector<int> list)
{
    for (int i : list)
    {
        cout << i << " ";
    }
    cout << "\n";
}
int main()
{
    Solution sol;
    vector<vector<int>> list = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = sol.mergeKArrays(list, list.size());
    display(ans);
    list = {{1, 2, 3, 4}, {2, 2, 3, 4}, {5, 5, 6, 6}, {7, 8, 9, 9}};
    ans = sol.mergeKArrays(list, list.size());
    display(ans);
    return 0;
}
