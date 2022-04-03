#include "Iterator.h"

Iterator::Iterator(HashTable*& hashTable) {
    this->hashTable = hashTable;
    this->now = hashTable->list->first->next;
}

Iterator::~Iterator() = default;

bool Iterator::hasNext() {
    return now != hashTable->list->first;
}

void Iterator::start() {
    now = hashTable->list->first->next;
}

void Iterator::next() {
    now = now->next;
}

int Iterator::seeElem() {
    return now->data;
}