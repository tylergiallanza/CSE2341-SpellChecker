#include "BKNode.h"

BKNode::BKNode(DSstring* valIn) {
    value = *valIn;
    for(int i=0;i<31;i++) {
        children[i] = NULL;
    }

}

void BKNode::add(BKNode* other) {
    int dist = value.levDist(other->value);
    if(children[dist] == NULL) {
        cout << endl << "Adding " << other->value << " to " << value << " at " << dist << endl;
        children[dist] = other;
    } else {
        cout << endl << "Adding " << other->value << " at " << dist << endl;
        children[dist]->add(other);
    }
}

void BKNode::print() {
    cout << value << endl;
    for(int i=0;i<31;i++) {
        if(children[i] == NULL)
            cout << i << ": " ;
        //children[i]->print();
    }
    cout << endl;
    for(int i=0;i<31;i++) {
        if(children[i] != NULL)
            cout << i << ": " ;
        //children[i]->print();
    }
    cout << endl;
}
