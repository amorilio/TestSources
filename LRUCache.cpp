#include "LRUCache.h"
#include <stdio.h>

LRUCache::LRUCache(void)
{
}

LRUCache::~LRUCache(void)
{
}

// A utility function to create a new Queue Node. The queue Node will store the given 'pageNumber'
LRUCache::QNode* LRUCache::newQNode( unsigned pageNumber )
{
    // Allocate memory and assign 'pageNumber'
    QNode* temp = new QNode();
    temp->pageNumber = pageNumber;

    // Initialize prev and next as NULL
    temp->prev = temp->next = nullptr;

    return temp;
}

// A utility function to create an empty Queue.
// The queue can have at most 'numberOfFrames' nodes
LRUCache::Queue* LRUCache::createQueue( int numberOfFrames )
{
    LRUCache::Queue* queue = new LRUCache::Queue();

    // The queue is empty
    queue->count = 0;
    queue->front = queue->rear = nullptr;

    // Number of frames that can be stored in memory
    queue->numberOfFrames = numberOfFrames;

    return queue;
}

// A utility function to create an empty Hash of given capacity
LRUCache::Hash* LRUCache::createHash( int capacity )
{
    // Allocate memory for hash
    Hash* hash = new Hash();
    hash->capacity = capacity;

    // Create an array of pointers for referring queue nodes
    hash->array = new QNode* [hash->capacity];

    // Initialize all hash entries as empty
    for( int i = 0; i < hash->capacity; ++i )        hash->array[i] = nullptr;

    return hash;
}

// A function to check if there is slot available in memory
int LRUCache::isQueueFull( Queue* queue )
{
    return queue->count == queue->numberOfFrames;
}

// A utility function to check if queue is empty
int LRUCache::isQueueEmpty( Queue* queue )
{
    return queue->rear == nullptr;
}

// A utility function to delete a frame from queue
void LRUCache::deQueue( Queue* queue )
{
    if( isQueueEmpty( queue ) )
        return;

    // If this is the only node in list, then change front
    if (queue->front == queue->rear)
        queue->front = nullptr;

    // Change rear and remove the previous rear
    QNode* temp = queue->rear;
    queue->rear = queue->rear->prev;

    if (queue->rear)
        queue->rear->next = nullptr;

    delete temp;

    // decrement the number of full frames by 1
    queue->count--;
}

// A function to add a page with given 'pageNumber' to both queue and hash
void LRUCache::enQueue( Queue* queue, Hash* hash, unsigned pageNumber )
{
    // If all frames are full, remove the page at the rear
    if ( isQueueFull ( queue ) )
    {
        // remove page from hash
        hash->array[ queue->rear->pageNumber ] = nullptr;
        deQueue( queue );
    }

    // Create a new node with given page number and add the new node to the front of queue
    QNode* temp = newQNode( pageNumber );
    temp->next = queue->front;

    // If queue is empty, change both front and rear pointers
    if ( isQueueEmpty( queue ) )
        queue->rear = queue->front = temp;
    else  // Else change the front
    {
        queue->front->prev = temp;
        queue->front = temp;
    }

    // Add page entry to hash also
    hash->array[ pageNumber ] = temp;

    // increment number of full frames
    queue->count++;
}

// This function is called when a page with given 'pageNumber' is referenced
// from cache (or memory). There are two cases:
// 1. Frame is not there in memory, we bring it in memory and add to the front of queue
// 2. Frame is there in memory, we move the frame to front of queue
void LRUCache::ReferencePage( Queue* queue, Hash* hash, unsigned pageNumber )
{
    QNode* reqPage = hash->array[ pageNumber ];

    // the page is not in cache, bring it
    if ( reqPage == nullptr )
        enQueue( queue, hash, pageNumber );

    // page is there and not at front, change pointer
    else if (reqPage != queue->front)
    {
        // Unlink requested page from its current location in queue.
        reqPage->prev->next = reqPage->next;
        if (reqPage->next)
            reqPage->next->prev = reqPage->prev;

        // If the requested page is rear, then change rear as this node will be moved to front
        if (reqPage == queue->rear)
        {
            queue->rear = reqPage->prev;
            queue->rear->next = nullptr;
        }

        // Put the requested page before current front
        reqPage->next = queue->front;
        reqPage->prev = nullptr;

        // Change prev of current front
        reqPage->next->prev = reqPage;

        // Change front to the requested page
        queue->front = reqPage;
    }
}

int TestLRUCache()
{
    LRUCache cache;
    // Let cache can hold 4 pages
    LRUCache::Queue* q = cache.createQueue( 4 );

    // Let 10 different pages can be requested (pages to be
    // referenced are numbered from 0 to 9
    LRUCache::Hash* hash = cache.createHash( 10 );

    // Let us refer pages 1, 2, 3, 1, 4, 5
    cache.ReferencePage( q, hash, 1);
    // Result : 1
    cache.ReferencePage(q, hash, 2);
    // Result : 2 1
    cache.ReferencePage(q, hash, 3);
    // Result : 3 2 1
    cache.ReferencePage(q, hash, 1);
    // Result : 1 3 2
    cache.ReferencePage(q, hash, 4);
    // Result : 4 1 3 2 
    cache.ReferencePage(q, hash, 5);
    // Result : 5 4 1 3 

    // Let us print cache frames after the above referenced pages
    printf ("%d ", q->front->pageNumber);
    printf ("%d ", q->front->next->pageNumber);
    printf ("%d ", q->front->next->next->pageNumber);
    printf ("%d ", q->front->next->next->next->pageNumber);
    
    TestLRUCacheSTL();

    return 0;
}

#include <unordered_map>
#include <iostream>
#include <iterator>

class LRUCacheSTL
{
public:
    LRUCacheSTL(int capacity) : _capacity(capacity) {}

    int get(int key)
    {
        std::cout << "------- Get " << key ;

        auto item = _cache.find(key);
        // if the key doesn't exist , return -1
        if (item == _cache.end())
            return -1;
        // if the key exists update the _lru (move coresponding value to the head) and return value 
        use(item);

        std::cout << " Value:" << item->second.first << std::endl;

        return item->second.first;
    }

    void set(int key, int value)
    {
        std::cout << "------- Set " << key << ":" << value << std::endl;

        // if the key exists just update it's value
        auto item = _cache.find(key);
        if (item != _cache.end())
        {
            use(item);
            _cache[key] = { value, _lru.begin() };
            return;
        }
        // if key doesnt exists
        // check capacity
        if (_cache.size() == _capacity)
        {
            _cache.erase(_lru.back());
            _lru.pop_back();
        }
        // insert new key value pair 
        _lru.push_front(key);
        _cache.insert({ key, { value, _lru.begin() } });
    }

    void use(std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator it)
    {
        _lru.erase(it->second.second);
        _lru.push_front(it->first);
        it->second.second = _lru.begin();
    }

    void printLRU()
    {
        std::cout << "------- Print " << std::endl;
        std::cout << "LRU	: ";
        for (auto i : _lru)
            std::cout << i << " ";
        std::cout << std::endl;
    

        std::cout << "CACHE	: ";
        std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator it = _cache.begin();
        while (it != _cache.end())
        {
            std::cout << "{" << *it->second.second << ":" << it->second.first << "} ";
            it++;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

private:
    
    int _capacity;

    std::list<int> _lru;

    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> _cache;

};

void TestLRUCacheSTL()
{
    std::cout << "------------- Start TestLRUCacheSTL ------------ - " << std::endl;

    LRUCacheSTL* lru = new LRUCacheSTL(4);
    lru->set(1, 1);
    lru->printLRU();
    lru->set(2, 2);
    lru->printLRU();
    lru->set(3, 3);
    lru->printLRU();
    lru->set(4, 4);
    lru->printLRU();

    // Should print value of key 2 and move key 2 to the beginning of the _LRU
    lru->get(2);
    lru->printLRU();

    // Should remove least recently used key (1) from the end of the _LRU and insert key (5) to the beginning with value 5 into the cache
    lru->set(5, 5);
    lru->printLRU();

    // Should update value of key(4) to 44 into the cache and move the key (4) to the beginning of the _LRU
    lru->set(4, 44);
    lru->printLRU();

    // No Change to _LRU , should print the value of key 44
    lru->get(4);
    lru->printLRU();

    //system("pause");
    std::cout << "------------- End TestLRUCacheSTL ------------ - " << std::endl;
}