#ifndef BK_TREE_H
#define BK_TREE_H
#include "BKNode.h"
#include "DSstring.h"

class BKTree{
    public:
        BKNode* rootNode;
        BKTree();
        void add(DSstring* str);
        void print();
};
#endif
