// User function Template for C++

#include <unordered_map>
#include <list>
using namespace std;

class Solution
{
public:
    int pageFaults(int n, int c, int pages[])
    {

        unordered_map<int, list<int>::iterator> mp;
        list<int> lru; // front = least recently used
        int pageFaults = 0;

        for (int i = 0; i < n; i++)
        {
            int page = pages[i];

            // If page is already in memory
            if (mp.find(page) != mp.end())
            {
                // Remove from current position
                lru.erase(mp[page]);
            }
            else
            {
                // Page fault
                pageFaults++;

                // If memory is full, remove LRU page
                if (lru.size() == c)
                {
                    int lruPage = lru.front();
                    lru.pop_front();
                    mp.erase(lruPage);
                }
            }

            // Insert current page as most recently used
            lru.push_back(page);
            mp[page] = --lru.end();
        }

        return pageFaults;
    }
};
