#include<stdio.h>

#define MAX_MEMORY_POOL_NODES 10

class NODE
{
public:
    explicit NODE(int node_allocated = 0) : data(0), nodeAllocated(node_allocated)    {    }

    int get_data() const	{		return data;	}
    void set_data(int data)	{		this->data = data;	}
    int get_node_allocated() const				{		return nodeAllocated;	}
    void set_node_allocated(int node_allocated)	{		nodeAllocated = node_allocated;	}

private:
    int		data;
    int		nodeAllocated;
};

typedef struct Memorypool
{
    NODE*	array[MAX_MEMORY_POOL_NODES];
    int     nodeCounter;
}MEMORYPOOL;

MEMORYPOOL pool;

/*
* initialiseMemoryPool()
*/
void initialiseMemoryPool()
{
    unsigned char uIndx;

    /* Initialise the Memory for the Nodes */
    for (uIndx = 0; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
    {
		pool.array[uIndx] = new NODE();
		pool.nodeCounter++;
    }
}

NODE *getTheFreeNodeFromPool()
{
    int uIndx;

    /* Get the Memory from the Pool of Nodes */
    for (uIndx = 0; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
    {
		if (pool.array[uIndx]->get_node_allocated() == 0)
        {
			pool.array[uIndx]->set_node_allocated(1);
			pool.nodeCounter--;
            break;
        }
    }

    if (uIndx == MAX_MEMORY_POOL_NODES)
    {
        printf(" No Free Nodes are available \n");
        return nullptr;
    }
	return pool.array[uIndx];
}

/*
*  Add the Node to Memory pool
*/
void addTheNodeToMemoryPool(unsigned char uIndx)
{
    /* Add the Node to Pool */
	if (pool.array[uIndx]->get_node_allocated() == 1)
    {
		pool.array[uIndx]->set_data(0);
		pool.array[uIndx]->set_node_allocated(0);
		pool.nodeCounter++;
    }
    else
    {
        printf("No Nodes are there Add \n");
    }
}

/*
* deallocateTheMemoryPool-  Deallocate the Memory Pool
*/
void deallocateTheMemoryPool(void)
{
    unsigned char uIndx;

    /* De-allocate the Memory Pool */
    for (uIndx = 0; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
    {
		delete pool.array[uIndx];
    }
}

int MemoryPoolTest()
{
    unsigned char uIndx, index;

    // Step 1:
    /* Initialise the Memory Pool */
    initialiseMemoryPool();

    // Step 2:
    /* Get the Node from the Memory Pool */
    for (uIndx = 0; uIndx< MAX_MEMORY_POOL_NODES; uIndx++)
    {
        int data;
        NODE *node = getTheFreeNodeFromPool();

        if (node)
        {
            printf("Enter the Data to be added in the Linklist \n");
            scanf("%d", &data);

            node->set_data( data ) ;
        }
    }

    /* Display the Data */
    printf(" Display Data \n");
    for (uIndx = 0; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
    {
		printf("%d\n", pool.array[uIndx]->get_data());
    }


    //Step 3:
    /* Add the Node to Memory Pool */
    printf(" Enter the Node to be added to memory pool \n");
    scanf("%d", &index);

    addTheNodeToMemoryPool(index);

    /* Display the Data */
    printf(" Display Data after adding Node to Free Pool \n");
    for (uIndx = 0; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
    {
		printf("%d\n", pool.array[uIndx]->get_data());
    }

    //Step 4:
    /* De Allocate the Memory Pool */
    deallocateTheMemoryPool();
    return 0;
}
