#include <iostream>
#include "HashMap.h"
#include <iterator> 


/*
Arrays

Set, Check element at a particular index: O(1)
Searching: O(n) if array is unsorted and O(log n) if array is sorted and something like a binary search is used,
           As pointed out by Aivean, there is no Delete operation available on Arrays. We can symbolically delete an element by setting it to some specific value, 
           e.g. -1, 0, etc. depending on our requirements Similarly, Insert for arrays is basically Set as mentioned in the beginning

ArrayList:

Add: Amortized O(1)
Remove: O(n)
Contains: O(n)
Size: O(1)

Linked List:

Inserting: O(1), if done at the head, O(n) if anywhere else since we have to reach that position by traveseing the linked list linearly.
Deleting: O(1), if done at the head, O(n) if anywhere else since we have to reach that position by traveseing the linkedlist linearly.
Searching: O(n)

Doubly-Linked List:

Inserting: O(1), if done at the head or tail, O(n) if anywhere else since we have to reach that position by traveseing the linkedlist linearly.
Deleting: O(1), if done at the head or tail, O(n) if anywhere else since we have to reach that position by traveseing the linkedlist linearly.
Searching: O(n)

Stack:

Push: O(1)
Pop: O(1)
Top: O(1)
Search (Something like lookup, as a special operation): O(n) (I guess so)

Queue/Deque/Circular Queue:

Insert: O(1)
Remove: O(1)
Size: O(1)

Binary Search Tree:
Insert, delete and search: Average case: O(log n), Worst Case: O(n)

Red-Black Tree:
Insert, delete and search: Average case: O(log n), Worst Case: O(log n)

Heap/PriorityQueue (min/max):

findMin/findMax: O(1)
insert: O(log n)
deleteMin/Max: O(log n)
lookup, delete (if at all provided): O(n), we will have to scan all the elements as they are not ordered like BST

HashMap/Hash table/HashSet:

Insert/Delete: O(1) amortized
Re-size/hash: O(n)
Contains: O(1)

*/



/*
map, set, multimap, and multiset - These are implemented using a red-black tree, a type of balanced binary search tree. They have the following asymptotic run times:

Insertion: O(log n)
Lookup: O(log n)
Deletion: O(log n)

hash_map, hash_set, hash_multimap, and hash_multiset - These are implemented using hash tables. They have the following run times:

Insertion: O(1) expected, O(n) worst case
Lookup: O(1) expected, O(n) worst case
Deletion: O(1) expected, O(n) worst case

If you use a proper hash function, you'll almost never see the worst case behavior, but it is something to keep in mind 


hash_map(unordered_map) use a hash table where the key is hashed to a slot in the table and the value is stored in a list tied to that key.

map is implemented as a balanced binary search tree(usually a red / black tree).

An unordered_map should give slightly better performance for accessing known elements of the collection,
but a map will have additional useful characteristics(e.g.it is stored in sorted order, which allows traversal from start to finish).
unordered_map will be faster on insert and delete than a map.

*/




//---------------- Linear probing Collision resolution Example ---------------- //
HashMap::HashMap() 
{
    table = new HashEntry*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

HashMap::~HashMap() 
{
    for (int i = 0; i < TABLE_SIZE; i++)
        if (table[i] != NULL)
            delete table[i];

    delete[] table;
}

int HashMap::get(int key) 
{
    int hash = (key % TABLE_SIZE);

    while (table[hash] != NULL && table[hash]->getKey() != key)
        hash = (hash + 1) % TABLE_SIZE;

    if (table[hash] == NULL)
        return -1;
    else
        return table[hash]->getValue();
}

void HashMap::put(int key, int value) 
{
    int hash = (key % TABLE_SIZE);
    while (table[hash] != NULL && table[hash]->getKey() != key)
        hash = (hash + 1) % TABLE_SIZE;

    if (table[hash] != NULL)
        delete table[hash];

    table[hash] = new HashEntry(key, value);
}  


//---------------- Chaining Collision resolution Example ---------------- //

HashMapChaining::HashMapChaining() 
{
        table = new LinkedHashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = NULL;
        }
}
HashMapChaining::~HashMapChaining() 
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != NULL) 
        {
            LinkedHashEntry *entry = table[i];
            while (entry != NULL) 
            {
                LinkedHashEntry *tmp = entry;
                entry = entry->getNext();
                delete tmp;
            }
        }
    }
    delete[] table;
}

int HashMapChaining::get(int key) 
{
    int hash = (key % TABLE_SIZE);
    if (table[hash] == NULL)
        return -1;
    else 
    {
        LinkedHashEntry *entry = table[hash];
        while (entry != NULL && entry->getKey() != key)
            entry = entry->getNext();

        if (entry == NULL)
            return -1;
        else
            return entry->getValue();
    }
}
void HashMapChaining::put(int key, int value) 
{
    int hash = (key % TABLE_SIZE);
    if (table[hash] == NULL)
        table[hash] = new LinkedHashEntry(key, value);
    else 
    {
        LinkedHashEntry *entry = table[hash];
        while (entry->getNext() != NULL && entry->getKey() != key)
            entry = entry->getNext();

        if (entry->getKey() == key)
            entry->setValue(value);
        else
            entry->setNext(new LinkedHashEntry(key, value));
    }
}
void HashMapChaining::remove(int key) 
{
    int hash = (key % TABLE_SIZE);
    if (table[hash] != NULL) 
    {
        LinkedHashEntry *prevEntry = NULL;
        LinkedHashEntry *entry = table[hash];
        while (entry->getNext() != NULL && entry->getKey() != key) 
        {
            prevEntry = entry;
            entry = entry->getNext();
        }

        if (entry->getKey() == key) 
        {
            if (prevEntry == NULL)
            {
                LinkedHashEntry *nextEntry = entry->getNext();
                delete entry;
                table[hash] = nextEntry;
            } else 
            {
                LinkedHashEntry *next = entry->getNext();
                delete entry;
                prevEntry->setNext(next);
            }
        }
    }
}


#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

template <class T>
void show(const T& x)
{
    for (const auto& i : x)
        cout << i.first << "; " << i.second << endl;
}

template <template < class ... > class T>
void map_test()
{
    map<string, int> x;
    x.insert(make_pair("one", 1));
    x.insert(make_pair("two", 2));
    x.insert(make_pair("three", 3));
    x.insert(make_pair("four", 4));

    show(x);
}

void maps_test()
{
    map_test<map>();
    cout << "*******************" << endl;
    map_test<unordered_map>();
}


#include <algorithm>

/*
Heap Operation Complexities:

push_heap - Logarithmic.At most log(last - first) comparisons.
pop_heap  - Logarithmic.At most 2 * log(last - first) comparisons.
make_heap - Linear.     At most 3 * (last - first) comparisons.
sort_heap - At most N * log(N) comparisons, where N is last - first.
is_heap   - Linear.Zero comparisons if[first, last) is an empty range, otherwise at most(last - first) - 1 comparisons.

*/
void heap_test()
{
    vector<int> vData; 
    int iSize = 10;
    int i = 0;
    while (i++ < iSize)
    {
        vData.push_back(rand() % 100);
    }

    cout << "Initial Vector  = " << endl;
    copy(vData.begin(), vData.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    // Make heap from initial vector 
    make_heap(vData.begin(), vData.end());
    cout << "heap  = " << endl;
    copy(vData.begin(), vData.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // Use push_back / make_heap of random element
    vData.push_back(rand() % 100);
    push_heap(vData.begin(), vData.end());
    cout << "heap after random push = " << endl;
    copy(vData.begin(), vData.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Get Max Heap Element
    cout << "Max Heap is :" << vData.front() << endl;

    // Pop from Heap
    pop_heap(vData.begin(), vData.end());
    cout << "heap after pop = " << endl;
    copy(vData.begin(), vData.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Remove poped element
    vData.pop_back();
    cout << "heap after removing = " << endl;
    copy(vData.begin(), vData.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // Check Is Heap and Heap Sort
    if(is_heap(vData.begin(), vData.end()))
        sort_heap(vData.begin(), vData.end());
    cout << "heap after Sort = " << endl;
    copy(vData.begin(), vData.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    priority_queue_test();
}

#include <queue>

class min_comparator
{
public:
    bool operator() (int i, int j){
        return i < j;
    };
};

class max_comparator
{
public:
    bool operator() (int i, int j){
        return i > j;
    };
};

void priority_queue_test()
{
    priority_queue<int, std::vector<int>, min_comparator> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(12);
    minHeap.push(3);
    minHeap.push(3);
    minHeap.push(4);

    cout << "Min Priority Queue: ";
    while (!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    priority_queue<int, std::vector<int>, max_comparator> maxHeap;

    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(12);
    maxHeap.push(3);
    maxHeap.push(3);
    maxHeap.push(4);

    cout << "Max Priority Queue: ";
    while (!maxHeap.empty()){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
}
