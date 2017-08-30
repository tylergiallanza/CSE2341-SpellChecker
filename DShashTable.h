#ifndef DS_HASH_TABLE_H
#define DS_HASH_TABLE_H

#include <iostream>
#include "DSlinkedList.h"

using namespace std;

template <class T>
class DShashTable {
    private:
        int size;
        DSlinkedList<T>* table;
        int hash(T item) {
            int seed = 131;
            unsigned long hash = 0;
            for(int i=0;i<item.length;i++) {
                hash = (hash*seed) + item.charAt(i);
            }
            hash *= item.length;
            return hash % size;
        }
    public:
 
        DShashTable<T>(int entries) {
            size = entries*2;
            table = new DSlinkedList<T>[size];
        }
        DShashTable<T>(const DShashTable& ht) {
            size = ht.size;
            table = new DSlinkedList<T>[size];
            for(int i=0;i<size;i++) {
                table[i] = ht[i];
            }
        }
        void add(T item) {
            int index = hash(item);
            table[index].add(item);
            cout << table[index] << " hashed" << endl;
        }
        bool check(T item) {
            int index = hash(item);
            while(table
        friend ostream& operator<<(ostream& os, const DShashTable& dsl) {
            return os;
        }
            
        DShashTable<T>& operator= (const DShashTable<T> &ht) {
            if(&table != this) {
            size = ht.size;
            table = new DSlinkedList<T>[size];
            for(int i=0;i<size;i++) {
                table[i] = ht[i];
            }
            }
            return *this;
        }
};
#endif
