#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int helper(vector<int> &arr)
{
    int candidate = -1, votes = 0;
    for (int i : arr)
    {
        if (votes == 0)
        {
            candidate = i;
            votes = 1;
        }
        else
        {
            if (i == candidate)
            {
                votes++;
            }
            else
            {
                votes--;
            }
        }
    }
    int count = 0;
    for (int i : arr)
    {
        if (i == candidate)
        {
            count++;
        }
    }
    if (count > floor(arr.size() / 3))
    {
        return candidate;
    }
    return -1;
};
int main()
{
    vector<int> arr = {1, 1, 1, 1, 2, 3, 4};
    cout << " The majority element is : " << helper(arr);
    return 0;
}