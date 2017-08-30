#include <iostream>
#include <fstream>
#include "DSstring.h"
#include "DSlinkedList.h"
#include "DShashTable.h"

int main(int argc, const char * argv[]) {

    int dictionary_size = 0;
    char A[30];
    DSstring* str;
    DSlinkedList<DSstring> list;
    DShashTable<DSstring> table(10);

    ifstream file(argv[1]);
    file >> dictionary_size;
    file.getline(A,32);
for(int i=0;i<dictionary_size;i++) {
    file.getline(A,32);
    str = new DSstring(A);
    cout << "str: " << *str << endl;
    //list.add(*str);
    table.add(*str);
}

}
