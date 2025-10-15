#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int row, col, elem;
    Node(int row, int col, int elem)
    {
        this->row = row;
        this->col = col;
        this->elem = elem;
    }
};
class Compare
{
public:
    bool operator()(const Node *a, const Node *b)
    {
        return a->elem > b->elem;
    }
};
class Solution
{
public:
    vector<int> findSmallestRange(vector<vector<int>> &arr)
    {
        int mini = INT32_MAX, maxi = INT32_MIN, k = arr.size(), n = arr[0].size();
        priority_queue<Node *, vector<Node *>, Compare> minHeap;
        for (int i = 0; i < k; i++)
        {
            int element = arr[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            minHeap.push(new Node(i, 0, element));
        }
        int start = mini, end = maxi;

        while (!minHeap.empty())
        {
            Node *temp = minHeap.top();
            minHeap.pop();
            mini = temp->elem;
            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }
            int nextCol = temp->col + 1;
            if (nextCol == n)
                break;
            int nextVal = arr[temp->row][nextCol];
            maxi = max(maxi, nextVal);
            minHeap.push(new Node(temp->row, nextCol, nextVal));
        }

        return {start, end};
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> arr = {{4, 7, 9, 12, 15}, {0, 8, 10, 14, 20}, {6, 12, 16, 30, 50}}; // 6,8
    vector<int> ans = sol.findSmallestRange(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {{1, 3, 5, 7, 9}, {0, 2, 4, 6, 8}, {2, 3, 5, 7, 11}}; // 1,2
    ans = sol.findSmallestRange(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {{2, 4}, {1, 7}, {20, 40}}; // 4,20
    ans = sol.findSmallestRange(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
