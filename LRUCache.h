#pragma once
class LRUCache
{
public:
    LRUCache(void);
    ~LRUCache(void);

    // A Queue Node (Queue is implemented using Doubly Linked List)
    typedef struct QNode
    {
        struct QNode *prev, *next;
        unsigned pageNumber;	 // the page number stored in this QNode
    } QNode;

    // A Queue (A FIFO collection of Queue Nodes)
    typedef struct Queue
    {
        unsigned count;			 // Number of filled frames
        unsigned numberOfFrames; // total number of frames
        QNode *front, *rear;
    } Queue;

    // A hash (Collection of pointers to Queue Nodes)
    typedef struct Hash
    {
        int capacity;			// how many pages can be there
        QNode* *array;			// an array of queue nodes
    } Hash;

    QNode*  newQNode( unsigned pageNumber );
    
    Queue*  createQueue( int numberOfFrames );
    Hash*   createHash( int capacity );

    int     isQueueFull( Queue* queue );
    int     isQueueEmpty( Queue* queue );
    
    void    deQueue( Queue* queue );
    void    enQueue( Queue* queue, Hash* hash, unsigned pageNumber );
    
    void    ReferencePage( Queue* queue, Hash* hash, unsigned pageNumber );
};

// Driver program to test above functions
int TestLRUCache();

void TestLRUCacheSTL();