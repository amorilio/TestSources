#pragma once

const int TABLE_SIZE = 128;

//---------------- Linear probing Collision resolution Example ---------------- //
class HashEntry {
private:
    int key;
    int value;
public:
    HashEntry(int key, int value) {
        this->key = key;
        this->value = value;
    }
    int getKey()   { return key;   }
    int getValue() { return value; }
};

class HashMap
{
private:
    HashEntry **table;
public:
    HashMap(void);
    ~HashMap(void);
    int get(int key);
    void put(int key, int value);
};

//---------------- Chaining Collision resolution Example ---------------- //
class LinkedHashEntry 
{
private:
    int key;
    int value;
    LinkedHashEntry *next;

public:
    LinkedHashEntry(int key, int value) : key(key), value(value), next(NULL)    {}
    int getKey()                        { return key; }
    int getValue()                      { return value; }
    void setValue(int value)            { this->value = value; }
    LinkedHashEntry *getNext()          { return next; }
    void setNext(LinkedHashEntry *next) { this->next = next; }
};

class HashMapChaining {

private:
    LinkedHashEntry **table;

public:
    HashMapChaining();
    ~HashMapChaining();

    int get(int key);
    void put(int key, int value);
    void remove(int key);
};


void heap_test();

void priority_queue_test();
