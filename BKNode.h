#ifndef BK_NODE_H
#define BK_NODE_H
#include "DSstring.h"

class BKNode;

class BKNode {
    public:
        DSstring value;
        BKNode* children[31];
        BKNode(DSstring* valIn);
        void add(BKNode* other);
        void print();
};

#endif
