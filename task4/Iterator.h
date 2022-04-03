#pragma once
#include "HashTable.h"

class Iterator
{
private:
    HashTable* hashTable;
    Element* now;

public:
    explicit Iterator(HashTable*& hashTable);

    ~Iterator();

    bool hasNext();

    void start();

    void next();

    int seeElem();
};