#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int> &arr)
    {
        int sum = 0;
        unordered_set<int> set;
        set.insert(0);
        for (int i : arr)
        {
            sum += i;
            if (set.find(sum) != set.end())
                return true;
            else
                set.insert(sum);
        }
        return false;
    }
};
int main()
{
    return 0;
}
