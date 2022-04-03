#pragma once

struct Element {
    int key;
    int data;
    Element* next;
    Element(int key, int data, Element* next = nullptr);
};

class HashList {
private:
    Element* first;
    Element* last;
public:
    friend class Iterator;

    HashList();

    ~HashList();

    void addElem(int elem, int key);

    void delElem(int elem);

    void doEmpty();
};

class HashTable
{
private:
    Element** hashTable;
    HashList* list;
    int size;
    int countElem;
    int HashFunc(int key);
public:
    friend class Iterator;

    explicit HashTable();

    explicit HashTable(int size);

    ~HashTable();

    void addElem(int elem, int key);

    void removeElem(int key);

    int getElem(int key);

    void doEmpty();

    bool isEmpty();

    void printElem();
};