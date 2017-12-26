#include "ReadWriteMutex.h"
#include <iostream>

ReadWriteMutex::ReadWriteMutex(int maxReaders) : m_maxReaders(maxReaders)
{
    m_semaphore = CreateSemaphore(nullptr, m_maxReaders, m_maxReaders, "ReaderSemaphore");
    m_mutex = CreateMutex(nullptr, FALSE, nullptr);

    if (m_semaphore == nullptr)		{/*Error Handling Here*/ }
    if (m_mutex == nullptr)			{/*Error Handling Here*/}
}

ReadWriteMutex::~ReadWriteMutex() {}


bool ReadWriteMutex::lockRead() const
{
    DWORD dwWaitResult = WaitForSingleObject(m_semaphore, 50L);
    switch (dwWaitResult)
    {
    case WAIT_OBJECT_0:
        return true;
    case WAIT_TIMEOUT:
    {
        std::cout << "ReadWriteMutex::lockRead WAIT_TIMEOUT" << std::endl;
        return false;
    }
    }
    return false;
}
void ReadWriteMutex::unlockRead() const
{
    ReleaseSemaphore(m_semaphore, 1, nullptr);
}
bool ReadWriteMutex::lockWrite() const
{

    DWORD dwWriteWaitResult = WaitForSingleObject(m_mutex, INFINITE);
    switch (dwWriteWaitResult)
    {
    case WAIT_OBJECT_0:
        for (int i = 0; i < m_maxReaders; ++i)
        {
            DWORD dwReadWaitResult = WaitForSingleObject(m_semaphore, 50L);
            switch (dwReadWaitResult)
            {
            case WAIT_OBJECT_0:
                return true;
            case WAIT_TIMEOUT:
            {
                printf("ReadWriteMutex::lockWrite WAIT_TIMEOUT\n");
                return false;
            }
            }
        }
        return true;
    case WAIT_ABANDONED:
        return false;
    }
    return false;
}
void ReadWriteMutex::unlockWrite() const
{
    ReleaseSemaphore(m_semaphore, m_maxReaders, nullptr);
    ReleaseMutex(m_mutex);
}

int value = 0;
#define THREADCOUNT 50
ReadWriteMutex m;

void ReaderRun(LPVOID lpParam)
{
    int *pId = static_cast<int*>(lpParam);
    m.lockRead();
    printf("%d Reader Thread %d read value %%\n", *pId, value);
    m.unlockRead();
}
void WriterRun(LPVOID lpParam)
{
    int *pId = static_cast<int*>(lpParam);
    m.lockWrite();
    value = rand() % *pId;
    printf("%d Writer Thread %d updated value to %%\n", *pId, value);
    m.unlockWrite();
}
void ReadWriteMutexTest()
{

    int* pThreadIDsArray[THREADCOUNT];
    HANDLE aThread[THREADCOUNT];
    DWORD ThreadID;
    for (int i = 0; i < THREADCOUNT; i++)
    {
        pThreadIDsArray[i] = static_cast<int*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(int*)));
        *pThreadIDsArray[i] = i + 1;
        int read_or_write = rand() % 2;
        if (read_or_write == 1)
        {
            //printf("--> CreateThread Reader : %d\n", *pThreadIDsArray[i]);
            aThread[i] = CreateThread(
                nullptr,                   // default security attributes
                0,                      // default stack size
                reinterpret_cast<LPTHREAD_START_ROUTINE>(ReaderRun),
                pThreadIDsArray[i],    // no thread function arguments
                0,                      // default creation flags
                &ThreadID);             // receive thread identifier
            if (aThread[i] == nullptr)
            {
                printf("CreateThread error: %d\n", GetLastError());
            }
        } else 
        {
            //printf("--> CreateThread Writer : %d\n", *pThreadIDsArray[i]);
            aThread[i] = CreateThread(
                nullptr,       // default security attributes
                0,          // default stack size
                reinterpret_cast<LPTHREAD_START_ROUTINE>(WriterRun),
                pThreadIDsArray[i],       // no thread function arguments
                0,          // default creation flags
                &ThreadID); // receive thread identifier
            if (aThread[i] == nullptr)
            {
                printf("CreateThread error: %d\n", GetLastError());
            }
        }
    }


    WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);

    // Close all thread handles and free memory allocations.
    for (int i = 0; i<THREADCOUNT; i++)
    {
        CloseHandle(aThread[i]);
        if (pThreadIDsArray[i] != nullptr)
        {
            HeapFree(GetProcessHeap(), 0, pThreadIDsArray[i]);
            pThreadIDsArray[i] = nullptr;    // Ensure address is not reused.
        }
    }
}