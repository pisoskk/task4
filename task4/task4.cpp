#include <iostream>
#include "HashTable.h"
#include "Iterator.h"

int main()
{
    HashTable* hashTable = new HashTable();
    for (int i = 0; i < 10; i++) {
        hashTable->addElem(i, i * i * i);
    }
    hashTable->addElem(15, 555);
    hashTable->addElem(17, 777);
    hashTable->addElem(27, 123);
    hashTable->printElem();
    std::cout << "---------------------" << std::endl;
    std::cout << "Elem with key {15} = " << hashTable->getElem(15) << std::endl;
    hashTable->removeElem(3);
    hashTable->removeElem(15);
    hashTable->removeElem(17);
    hashTable->printElem();
    std::cout << "---------------------" << std::endl;
    Iterator it(hashTable);
    while (it.hasNext()) {
        std::cout << it.seeElem() << std::endl;
        it.next();
    }
    std::cout << "---------------------" << std::endl;
    std::cout << "is empty ? - " << hashTable->isEmpty() << std::endl;
    hashTable->doEmpty();
    std::cout << "now, is empty ? - " << hashTable->isEmpty() << std::endl;
    std::cout << "---------------------" << std::endl;
}