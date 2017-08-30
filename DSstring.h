#ifndef DS_STRING_H
#define DS_STRING_H

#include <iostream>
using namespace std;

class DSstring {
    private:
        char* cstring;
        int recursiveLevDist(int i, int j, const DSstring& other);
    public:
        int length;
        DSstring(char* cstringIn);
        DSstring(const DSstring& str);
        DSstring();
        int levDist(const DSstring& other);
        char charAt(int loc);
        friend ostream& operator<<(ostream& os, const DSstring& dss);
        DSstring& operator= (const DSstring &str);
};
#endif
