#pragma once

#include <windows.h>

class ReadWriteMutex
{
public:
    ReadWriteMutex(int maxReaders = 32);
    virtual ~ReadWriteMutex();
    bool lockRead() const;
    void unlockRead() const;
    bool lockWrite() const;
    void unlockWrite() const;

private:
    int m_maxReaders;

    HANDLE m_semaphore;
    HANDLE m_mutex;
};

void ReadWriteMutexTest();