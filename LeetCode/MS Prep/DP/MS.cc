// Datastream int: input can be in any order
// Median (double) even or odd number of numbers can be there in DS

// Eliminating use of set because we can get duplicates

// Time-complexity:
// Approach 1: Sorting vector O(N logN)
// Approach 2: BST O(Height of the tree) |  E/O L M R - Maths
// Approach 3: PQ - Insert all numbers in DS.. then start popping after N/2 pops return the top is N is odd. min PQ max PQ.
// Left - max
// Right - min

#include <iostream>
#include <vector>
#include <priority_queue>

using namespace std;

class approach_1
{
    vector<int> vec;

public:
    approach_1()
    {
        vec.clear();
    }
    void ingest_ds(int a)
    {
        vec.push_back(a);
    }

    double median()
    {
        int N = (int)vec.size();
        if (N == 0)
            return 0;

        sort(vec.begin(), vec.end()); // O(N log N)
        if (N % 2 == 1)
            return (double)vec[N / 2];
        else
            return (double)(vec[N / 2] + vec[N / 2 - 1]) / 2;
    }
};

Solution approach_2
{

    priority_queue<int, vector<int>, greater<>> pq_min; //pq_min.top() = min
    priority_queue<int> pq_max;

public:
    approach_2()
    {
        pq_min.clear();
        pq_max.clear();

        void ingest_ds(int a)
        {
            pq_min.push(a); //23
            prepare_pq_max();
            if (pq_min.size() < pq_max.size())
            {
                pq_min.insert(pq_max.top());
                pq_max.pop();
            }
        }
        void prepare_pq_max()
        {
            pq_max.insert(pq_min.top()); //1
            pq_min.pop();
        }

        double median()
        {
            if (pq_min.size() == 0)
                return 0;
            int N = (int)pq_min.size();

            if (N % 2 == 1)
                return (double)pq_min.top();
            else
                return (double)(pq_min.top() + pq_max.top() / 2);
        }
    }
    ------
#include <iostream>

        int
        main()
    {
        // you can write to stdout for debugging purposes, e.g.
        std::cout << "This is a debug message" << std::endl;

        return 0;
    }

    {
    Memory:
        100 MB;
        // Assumption: Secondary disk is durable
        // Maintain a map on secondary memory - XML/JSON file - synced
        // Insertion
        // if key is already - error
        // else - map[key] = value[] - disadvantage : its not fault tolerant / durability
        // return true
        // LRU
        // Retrieve
        // O(1) : map[key]!=map.end() return map[key];
        // else not found;
        // Rebuilding the map
        //
    }

#define limit 1000

    class LRUCache
    {
        // FIFO
        // (stale) a, b, d... .e end (fresh)

        queue<int> LRU;

        void updateLRU(int key)
        {
            if (LRU.size() == limit)
            {
                LRU.pop(); //  pop from front
            }
            LRU.push(key); // push the key in the end
        }

    public:
        LRUCache()
        {
            LRU.clear();
        }
        vector<int> retrive(int key)
        {
            updateLRU(key);

            if (map.find(key) != map.end()) //found the keu
                return map[key];

            return {}; //not found
        }

        int insert(int key, vector<int> value)
        {

            updateLRU(key);
            if (map.find(key) != map.end())
                return -1; //key already present

            map[key] = value;

            return 1; //success
        }

        int delete (int key)
        {
            updateLRU(key);
            //   if(map.find(key)== map.end()) //not found
            //     return -1;

            return map.erase(key);
        }
    }
