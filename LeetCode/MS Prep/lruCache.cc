#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

class LRUCache {
    int cap;
    map<int, int> myCache;
    queue<int> q;
    
public:
    LRUCache(int capacity) {
      
        cap = capacity;
        }

    int get(int key) {
        if (myCache.find(key) != myCache.end())
            {  //update freshnss of key - delete/overwrite old freshness score
            q.push(key);
            evict();
            return myCache[key];
            }

        return -1;
        }

    void put(int key, int value) {

        if (myCache.find(key) != myCache.end())
            {
            //update freshness of key
           
            myCache[key] = value;
           
            }
        else
            {
            // make new entry in the freshness table for key 
            myCache.insert(pair<int, int>(key, value));
            
            }
         evict();
        }
    void evict()
        {
         if (myCache.size() > cap)
             {
             myCache.erase((myCache.find(q.front())));
             q.pop();
            }
        }
    };

int main()
    {

    LRUCache Obj(4);

    }
