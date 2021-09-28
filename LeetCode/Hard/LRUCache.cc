#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
    int cap;
    deque<int> dq;
    unordered_map<int, int> cache;
    int curr_cache_size = 0;

  public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }
    void delfromdq(int k)
    {
        for (int i = 0; i < dq.size(); i++)
        {
            if (dq[i] == k)
            {
                dq.erase(dq.begin(), dq.begin() + i);

                break;
            }
        }
    }
    int get(int key)
    {
        int ret;
        (cache.find(key) != cache.end()) ? ret = cache.find(key)->second : ret = -1; //return the value for Key
        if (ret != -1)
        {
            int v;
            v = cache[key];
            cache.erase(key);
            delfromdq(key);
            put(key, v);
        }
        return ret;
    }

    void put(int key, int value)
    {
        if (cap <= 0)
            return;
        int evict;

        if (cache.find(key) != cache.end())
        {
            delfromdq(key);
            cache.erase(key);
        }
        if (cache.size() == cap) //cache reaches the maximum capacity
        {
            evict = dq.front();
            dq.pop_front();     //remove Key from the queue
            cache.erase(evict); //erase Key from cache map
        }
        cache[key] = value;
        dq.emplace_back(key);
    }
    void printdq()
    {
        cout << "DQ ";
        for (auto d : dq)
            cout << d << " ";
        cout << endl;
    }
    void printCache()
    {

        for (auto i : cache)
            cout << "-> " << i.first << "\t" << i.second << endl;

        cout << "Size of cache = " << cache.size() << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
    int capacity = 2;
    int key, value;

    LRUCache cache(capacity);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n"; // returns 1
    //cache.put(3, 3);              // evicts key 2
    cache.printdq();
    cache.printCache();
    cache.delfromdq(1);
    cache.printdq();
    // cout << cache.get(2) << "\n"; // returns -1 (not found)
    // cache.put(4, 4);              // evicts key 1
    // cout << cache.get(1) << "\n"; // returns -1 (not found)
    // cout << cache.get(3) << "\n"; // returns 3
    // cout << cache.get(4) << "\n"; // returns 4
}