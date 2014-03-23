// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. 
//                   When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 

#include <iostream>
#include <vector>
#include <utility>  // pair
#include <unordered_map>

using namespace std;

class LRUCache
{
    public:
        LRUCache(int capacity) : heap(capacity), max(0), cnt(0) {}

        int get(int key)
        {
            unordered_map<int,int>::iterator it = table.find(key);
            if (it != table.end())
            {
                int idx = it->second;
                int value = heap[idx].value;
                heap[idx].priority = (++max);
                idx = popdown(idx);
                //it->second = idx;
                table[heap[idx].key] = idx;
                return value;
            }
            else
            {
                return -1;
            }
        }

        void set(int key, int value)
        {
            unordered_map<int,int>::iterator it = table.find(key);
            if (it != table.end())
            {
                int idx = it->second;
                heap[idx].key = key;
                heap[idx].value = value;
                heap[idx].priority = (++max);

                idx = popdown(idx);
                table[heap[idx].key] = idx;
                //it->second = idx;
            }
            else
            {
                if (cnt == heap.size())
                {
                    table.erase(heap[0].key);

                    heap[0].key = key;
                    heap[0].value = value;
                    heap[0].priority = (++max);

                    int idx = popdown(0);
                    table[heap[idx].key] = idx;
                    //table.insert(pair<int,int>(key,idx));
                }
                else
                {
                    cnt++;
                    heap[cnt-1].key = key;
                    heap[cnt-1].value = value;
                    heap[cnt-1].priority = (++max);
                    table[key] = cnt-1;
                    //table.insert(pair<int,int>(key, cnt-1));
                }
            }
        }

        inline int parent(int child)
        {
            return (child-1)/2;
        }

        inline int leftchild(int parent)
        {
            return (2*parent+1);
        }

        inline int rightchild(int parent)
        {
            return (2*parent+2);
        }

        void swap(int i, int j)
        {
            HeapElement tmp = heap[i];
            heap[i] = heap[j];
            table[heap[i].key] = i;
            heap[j] = tmp;
            table[heap[j].key] = j;
        }

        int popdown(int idx)
        {
            int i = idx;
            while (i < cnt)
            {
                int lc = leftchild(i);
                int rc = rightchild(i);
                int small = i;
                if (lc < cnt && heap[lc].priority <= heap[i].priority)
                {
                    small = lc;
                }
                if (rc < cnt && heap[rc].priority <= heap[small].priority)
                {
                    small = rc;
                }
                if (i != small)
                {
                    swap(i, small);
                    i = small;
                }
                else
                {
                    break;
                }
            }
            return i;
        }

    private:
        // hashtable element: key, pointer to heap element
        // min heap element : key, value, priority

        class HeapElement
        {
            public:
                int key;
                int value;
                int priority;
        };

        unordered_map<int,int> table;
        vector<HeapElement> heap;
        int max;
        int cnt;
};

class LRUCache2{
    public:
        LRUCache2(int capacity) : n(capacity), size(0), head(new CacheNode(-1,-1)), tail(new CacheNode(-1,-1)) {
            head->next = tail;
            tail->prev = head;
        }

        ~LRUCache2()
        {
            delete head;
            delete tail;
        }

        int get(int key) {
            unordered_map<int,CacheNode*>::iterator it = table.find(key);

            // unsuccessful search
            if (it == table.end())
            {
                return -1;
            }

            // successful search
            // fetch the value and put node to tail
            int v = it->second->value;

            CacheNode *t = it->second;
            t->prev->next = t->next;
            t->next->prev = t->prev;

            moveBack(t);

            return v;
        }

        void set(int key, int value) {
            unordered_map<int,CacheNode*>::iterator it = table.find(key);

            if (it != table.end())  // successful search
            {
                CacheNode *t = it->second;
                t->value = value;
                t->prev->next = t->next;
                t->next->prev = t->prev;

                moveBack(t);
            }
            else
            {
                if (size == n)   // remove the least recent node
                {
                    CacheNode *first = head->next;
                    head->next = first->next;
                    first->next->prev = head;
                    table.erase(first->key);
                    delete first;
                    size--;
                }

                CacheNode *t = new CacheNode(key, value);
                moveBack(t);

                table.insert(pair<int,CacheNode*>(key, t));
                size++;
            }
        }

    private:
        // doubly linked list + hashtable
        struct CacheNode
        {
            int key;
            int value;
            CacheNode *prev;
            CacheNode *next;
            CacheNode(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
        };

        void moveBack(CacheNode *t)
        {
            t->prev = tail->prev;
            t->next = tail;
            tail->prev->next = t;
            tail->prev = t;
        }

        int n;
        int size;
        CacheNode *head;
        CacheNode *tail;
        unordered_map<int,CacheNode*> table;
};

int main()
{
    LRUCache2 lru(1);

    lru.set(2,1);
    cout << "get(2) = " << lru.get(2) << endl;
    lru.set(3,2);
    cout << "get(2) = " << lru.get(2) << endl;
    cout << "get(3) = " << lru.get(3) << endl;

    return 0;
}
