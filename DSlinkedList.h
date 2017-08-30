#ifndef DS_LINKED_LIST_H
#define DS_LINKED_LIST_H

#include <iostream>
using namespace std;

template <class T>
class DSlinkedListNode;
template <class T>
class DSlinkedListNode {
    public:
        T value;
        DSlinkedListNode* next;
        friend ostream& operator<<(ostream& os, const DSlinkedListNode& dsn) {
            os << dsn.value;
            if(dsn.next != NULL) {
                os << " " << *(dsn.next);
            }
            return os;
        }

};
template <class T>
class DSlinkedList {
    private:
        DSlinkedListNode<T>* rootNode;
        DSlinkedListNode<T>* lastNode;
    public:
 
        DSlinkedList<T>() {
            rootNode = NULL;
            lastNode = NULL;
        }
        DSlinkedList<T>(const DSlinkedList& list) {
            DSlinkedListNode<T>* current = list.rootNode;
            DSlinkedListNode<T>* newRoot = NULL;
            while(current != NULL) {
                DSlinkedListNode<T>* temp = new DSlinkedListNode<T>; 
                temp->value = current->value;
                temp->next = NULL;
                if(newRoot != NULL) {
                    newRoot->next = temp;
                } else {
                    newRoot = temp;
                }
           
                current = current->next;
                lastNode = temp;
            }

            rootNode = list.rootNode;
        }
        void add(T item) {
            DSlinkedListNode<T>* temp = new DSlinkedListNode<T>;
            temp->value = item;
            if(rootNode == NULL) {
                rootNode = temp;
            } else {
                lastNode->next = temp;
            }
            lastNode = temp;
        }
        bool isEmpty() { return rootNode == NULL; }

        friend ostream& operator<<(ostream& os, const DSlinkedList& dsl) {
            os << "linked list <" << *(dsl.rootNode) << ">";
            return os;
        }
            
        DSlinkedList<T>& operator= (const DSlinkedList<T> &list) {
            if(&list != this) {
            DSlinkedListNode<T>* current = list.rootNode;
            DSlinkedListNode<T>* newRoot = NULL;
            while(current != NULL) {
                DSlinkedListNode<T>* temp = new DSlinkedListNode<T>; 
                temp->value = current->value;
                temp->next = NULL;
                if(newRoot != NULL) {
                    newRoot->next = temp;
                } else {
                    newRoot = temp;
                }
           
                current = current->next;
            }

            rootNode = list.rootNode;
            }
            return *this;
        }
};
#endif
