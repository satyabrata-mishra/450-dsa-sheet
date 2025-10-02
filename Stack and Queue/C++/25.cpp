#include <iostream>
#include <map>
using namespace std;
class LRUCache
{
private:
    map<int, int> map;
    int capacity = -1;

public:
    LRUCache(int cap)
    {
        map.clear();
        capacity = cap;
    }

    int get(int key)
    {
        auto it = map.find(key);
        if (it == map.end())
            return -1;
        int value = it->second;
        map.erase(it); // Remove the accessed element
        map[key] = value;
        return value;
    }
    void display()
    {
        for (pair<int, int> i : map)
            cout << i.first << "->" << i.second << ",";
        cout << "\n";
    }
    void put(int key, int value)
    {
        if (map.size() == capacity)
            map.erase(map.begin());
        map[key] = value;
    }
};
int main()
{
    // LRUCache ob(2);
    // ob.put(1, 2);
    // cout << ob.get(1) << "\n";
    // ob = LRUCache(2);
    // ob.put(1, 2);
    // ob.put(2, 3);
    // ob.put(1, 5);
    // ob.put(4, 5);
    // ob.put(6, 7);
    // cout << ob.get(4) << "\n";
    // ob.put(1, 2);
    // cout << ob.get(3) << "\n";
    // return 0;
    LRUCache largeCache(5); // Cache with capacity 5
    largeCache.put(1, 10);
    largeCache.put(2, 20);
    largeCache.put(3, 30);
    largeCache.put(4, 40);
    largeCache.put(5, 50);
    cout << largeCache.get(1) << "\n"; // Expected: 10 (key 1 is present)
    largeCache.display();
    largeCache.put(6, 60);             // Evicts key 2 (LRU)
    cout << largeCache.get(2) << "\n"; // Expected: -1 (key 2 has been evicted)
    cout << largeCache.get(6) << "\n"; // Expected: 60 (key 6 is present)
    cout << largeCache.get(3) << "\n"; // Expected: 30 (key 3 is present)
    cout << largeCache.get(4) << "\n"; // Expected: 40 (key 4 is present)
    largeCache.put(7, 70);             // Evicts key 5 (LRU)
    cout << largeCache.get(5) << "\n"; // Expected: -1 (key 5 has been evicted)
    largeCache.put(8, 80);             // Evicts key 1 (LRU)
    cout << largeCache.get(1) << "\n"; // Expected: -1 (key 1 has been evicted)
    cout << largeCache.get(7) << "\n"; // Expected: 70 (key 7 is present)

    return 0;
}
