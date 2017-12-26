// Threads.cpp: implementation of the Threads class.
//
//////////////////////////////////////////////////////////////////////

#include "Threads.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/*
#include <windows.h>
class RWLock
{
public:
RWLock() : m_nReaders(0) { }
virtual ~RWLock() { }

  void AcquireWriteLock() const	{ WaitForSingleObject(m_hDataEvent, INFINITE); }
  void ReleaseWriteLock() const	{ SetEvent(m_hDataEvent); }
  void AcquireReadLock()			{
	HANDLE handles[2] = { m_hDataEvent, m_hAnotherDataEvent };
	WaitForMultipleObjects(2, handles, TRUE, INFINITE);

	  WaitForSingleObject(m_hReadersEvent, INFINITE);
	  if (m_nReaders++ == 0)
	  WaitForSingleObject(m_hDataEvent, INFINITE);
	  SetEvent(m_hReadersEvent);
	  }
	  void ReleaseReadLock()			{
	  WaitForSingleObject(m_hReadersEvent, INFINITE);
	  if (--m_nReaders == 0)
	  SetEvent(m_hDataEvent);
	  SetEvent(m_hReadersEvent);
	  }

		private:
		int      m_nReaders;
		HANDLE   m_hReadersEvent;
		HANDLE   m_hDataEvent;
		HANDLE	 m_hAnotherDataEvent;
		  };

			struct LockRequest
			{
			enum LockType_En		{ READ_LOCK, WRITE_LOCK };
			LockRequest(RWLock* pRWLock, LockType_En lockType) : m_pRWLock(pRWLock), m_lockType(lockType) {};
			RWLock* m_pRWLock;
			LockType_En m_lockType;
			};

			  static void RWLock::MultipleRWLock(LockRequest* pRequest, int nCount)
			  {
			  HANDLE		dataHandles[MAXIMUM_WAIT_OBJECTS];
			  RWLock*		readers[MAXIMUM_WAIT_OBJECTS];
			  int nDataHandles = 0, nReaders= 0;

				for (int i = 0; i < nCount; i++)
				{
				// Build data handles array
				dataHandles[nDataHandles++] = pRequest[i].m_pRWLock->m_hAnotherDataEvent;
				if (pRequest[i].m_lockType == LockRequest::WRITE_LOCK)
				dataHandles[nDataHandles++] = pRequest[i].m_pRWLock->m_hDataEvent;
				else
				// Build readers array
				readers[nReaders++] = pRequest[i].m_pRWLock;
				}

				  // Perform the locks
				  WaitForMultipleObjects(nDataHandles, dataHandles, TRUE, INFINITE);

					// For each read request update readers counter
					for (i = 0; i < nReaders; i++)
					{
					readers[i]->AcquireReadLock();
					SetEvent(readers[i]->m_hAnotherDataEvent);
					}
					}
*/

/*

// Example of Multi Reader Single Writer implementation.

#include "windows.h"
class MultiReaderSingleWriter
{
private:
    CRITICAL_SECTION m_csWrite;
    CRITICAL_SECTION m_csReaderCount;
    long m_cReaders;
    HANDLE m_hevReadersCleared;

public:
    MultiReaderSingleWriter()
    {
        m_cReaders = 0;
        InitializeCriticalSection(&m_csWrite);
        InitializeCriticalSection(&m_csReaderCount);
        m_hevReadersCleared = CreateEvent(NULL,TRUE,TRUE,NULL);
    }

    ~MultiReaderSingleWriter()
	{
		WaitForSingleObject(m_hevReadersCleared,INFINITE);
		CloseHandle(m_hevReadersCleared);
		DeleteCriticalSection(&m_csWrite);
		DeleteCriticalSection(&m_csReaderCount);
	}

	void EnterReader(void)
	{
		EnterCriticalSection(&m_csWrite);
		EnterCriticalSection(&m_csReaderCount);
		if (++m_cReaders == 1)
			ResetEvent(m_hevReadersCleared);
		LeaveCriticalSection(&m_csReaderCount);
		LeaveCriticalSection(&m_csWrite);
	}

	void LeaveReader(void)
	{
		EnterCriticalSection(&m_csReaderCount);
			if (--m_cReaders == 0)
		SetEvent(m_hevReadersCleared);
		LeaveCriticalSection(&m_csReaderCount);
	}

	void EnterWriter(void)
	{
		EnterCriticalSection(&m_csWrite);
		WaitForSingleObject(m_hevReadersCleared,INFINITE);
	}

	void LeaveWriter(void)
	{
		LeaveCriticalSection(&m_csWrite);
	}
};
*/

HANDLE ghSemaphore;

DWORD WINAPI ThreadProc( LPVOID lpParam )
{
    // lpParam not used in this example
    UNREFERENCED_PARAMETER(lpParam);

    DWORD dwWaitResult;
    BOOL bContinue=TRUE;

    while(bContinue)
    {
        // Try to enter the semaphore gate.

        dwWaitResult = WaitForSingleObject(
            ghSemaphore,   // handle to semaphore
            0L);           // zero-second time-out interval

        switch (dwWaitResult)
        {
            // The semaphore object was signaled.
		case WAIT_OBJECT_0:
			// TODO: Perform task
			printf("Thread %d: wait succeeded\n", GetCurrentThreadId());
			bContinue=FALSE;

			// Simulate thread spending time on task
			Sleep(5);

			// Release the semaphore when task is finished

			if (!ReleaseSemaphore(
				ghSemaphore,  // handle to semaphore
				1,            // increase count by one
				NULL) )       // not interested in previous count
			{
				printf("ReleaseSemaphore error: %d\n", GetLastError());
			}
			break;

            // The semaphore was nonsignaled, so a time-out occurred.
		case WAIT_TIMEOUT:
			printf("Thread %d: wait timed out\n", GetCurrentThreadId());
			break;
        }
    }
    return TRUE;
}

Threads::Threads()
{
    HANDLE aThread[THREADCOUNT];
    DWORD ThreadID;
    int i;

    // Create a semaphore with initial and max counts of MAX_SEM_COUNT

    ghSemaphore = CreateSemaphore(
        NULL,           // default security attributes
        MAX_SEM_COUNT,  // initial count
        MAX_SEM_COUNT,  // maximum count
        NULL);          // unnamed semaphore

    if (ghSemaphore == NULL)
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return;
    }

    // Create worker threads

    for( i=0; i < THREADCOUNT; i++ )
    {
        aThread[i] = CreateThread(
			NULL,       // default security attributes
			0,          // default stack size
			(LPTHREAD_START_ROUTINE) ThreadProc,
			NULL,       // no thread function arguments
			0,          // default creation flags
			&ThreadID); // receive thread identifier

        if( aThread[i] == NULL )
        {
            printf("CreateThread error: %d\n", GetLastError());
            return;
        }
    }

    // Wait for all threads to terminate

    WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);

    // Close thread and semaphore handles

    for( i=0; i < THREADCOUNT; i++ )
        CloseHandle(aThread[i]);

    CloseHandle(ghSemaphore);

    return;
}

Threads::~Threads()
{
}