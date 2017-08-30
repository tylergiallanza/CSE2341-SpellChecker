#include "BKTree.h"
#include "BKNode.h"

BKTree::BKTree() {
    rootNode = NULL;
}

void BKTree::add(DSstring* str) {
    if(rootNode == NULL) {
        rootNode = new BKNode(str);
        cout << "BKT: added " << rootNode->value << " as root" << endl;
    }
    else {
        BKNode* node = new BKNode(str);
        cout << "BKT: root node is " << rootNode->value << ". Adding " << *str;
        rootNode->add(node);
    }
}

void BKTree::print() {
    if(rootNode != NULL) {
        rootNode->print();
    }
}
