#include "HashTable.h"
#include <iostream>

Element::Element(int key, int data, Element* next) {
    this->key = key;
    this->data = data;
    this->next = next;
}

// !!! list 

HashList::HashList() {
    first = new Element(0, 0);
    last = first;
    last->next = first;
}

HashList::~HashList() {
    doEmpty();
}

void HashList::addElem(int key, int elem) {
    last->next = new Element(key, elem);
    last = last->next;
    last->next = first;
}

void HashList::delElem(int elem) {
    Element* buf = first;
    Element* temp = first->next;
    while (temp->data != elem) {
        buf = temp;
        temp = temp->next;
    }
    buf->next = temp->next;
    delete temp;
}

void HashList::doEmpty() {
    Element* temp = first->next;
    while (temp != last) {
        temp = temp->next;
        delete first;
        first = temp;
    }
    delete first;
    last = first;
    last->next = first;
}

// !!! list 

int HashTable::HashFunc(int key) {
    return key % this->size;
}

HashTable::HashTable() {
    countElem = 0;
    size = 10;
    hashTable = new Element * [10];
    list = new HashList();
    for (int i = 0; i < size; i++) {
        hashTable[i] = nullptr;
    }
}

HashTable::HashTable(int size) {
    countElem = 0;
    this->size = size;
    hashTable = new Element * [size];
    list = new HashList();
    for (int i = 0; i < size; i++) {
        hashTable[i] = nullptr;
    }
}

HashTable::~HashTable() {
    doEmpty();
    delete[] hashTable;
    delete list;
    hashTable = nullptr;
    list = nullptr;
}

void HashTable::addElem(int key, int elem) {
    int position = HashFunc(key);
    if (!hashTable[position]) {
        hashTable[position] = new Element(key, elem);
    }
    else {
        Element* temp = hashTable[position];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Element(key, elem);
    }
    list->addElem(key, elem);
    countElem++;
}

void HashTable::removeElem(int key) {
    int position = HashFunc(key);
    Element* temp = hashTable[position];
    Element* buf = temp;
    while (temp) {
        if (key == temp->key) {
            if (buf == temp) {
                hashTable[position] = temp->next;
            }
            else {
                buf->next = temp->next;
            }
            list->delElem(temp->data);
            delete temp;
            countElem--;
            return;
        }
        buf = temp;
        temp = temp->next;
    }
    throw std::exception("No elem");
}

int HashTable::getElem(int key) {
    int position = HashFunc(key);
    Element* temp = hashTable[position];
    while (temp) {
        if (key == temp->key) {
            return temp->data;
        }
        temp = temp->next;
    }
    throw std::exception("No elem");
}

void HashTable::doEmpty() {
    for (int i = 0; i < size; i++) {
        Element* temp = hashTable[i];
        Element* buf;
        while (temp) {
            buf = temp->next;
            delete temp;
            temp = buf;
        }
        hashTable[i] = nullptr;
    }
    list->doEmpty();
    countElem = 0;
}

bool HashTable::isEmpty() {
    return countElem == 0;
}

void HashTable::printElem() {
    for (int i = 0; i < size; i++) {
        Element* temp = hashTable[i];
        std::cout << i << ": ";
        while (temp) {
            std::cout << " " << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}