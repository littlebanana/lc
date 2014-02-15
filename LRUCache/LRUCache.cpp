#include <iostream>
#include <vector>
#include <utility>  // pair
#include <unordered_map>

using namespace std;

class LRUCache{
    public:
        LRUCache(int capacity) : heap(capacity), max(0), cnt(0) {
        }

        int get(int key) {
            unordered_map<int,int>::iterator it = table.find(key);
            if (it != table.end())
            {
                int idx = it->second;
                int value = heap[idx].value;
                heap[idx].priority = (++max);

                idx = popdown(idx);
                //it->second = idx;
                return value;
            }
            else
            {
                cout << "here" << endl;
            }
        }

        void set(int key, int value) {
            cout << "set(" << key << "," << value << ")" << endl;
            unordered_map<int,int>::iterator it = table.find(key);
            if (it != table.end())
            {
                int idx = it->second;
                heap[idx].value = value;
                heap[idx].priority = (++max);

                idx = popdown(idx);
                it->second = idx;
                cout << "key = " << it->first;
                cout << "idx = " << it->second << endl;
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
                    //table.insert(pair<int,int>(key,idx));
                    cout << "key = " << key;
                    cout << "idx = " << idx << endl;
                }
                else
                {
                    cnt++;
                    heap[cnt-1].key = key;
                    heap[cnt-1].value = value;
                    heap[cnt-1].priority = (++max);
                    table.insert(pair<int,int>(key, cnt-1));
                    cout << "key = " << key;
                    cout << "idx = " << cnt-1 << endl;
                }
            }

            for (int i = 0; i < cnt; i++)
            {
                cout << "(" << heap[i].key << "," << heap[i].value << ")" << endl;
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

int main()
{
    LRUCache lru(1);

    lru.set(2,1);
    cout << "get(2) = " << lru.get(2) << endl;
    lru.set(3,2);
    cout << "get(2) = " << lru.get(2) << endl;
    cout << "get(3) = " << lru.get(3) << endl;

    return 0;
}
