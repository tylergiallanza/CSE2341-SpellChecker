#include "DSstring.h"
#include <algorithm>

using namespace std;

DSstring::DSstring(char* cstringIn) {
    length=0;
    while(cstringIn[length] != '\0') {
        length++;
    }
    cstring = new char[length];
    //cout << cstringIn << " " << length << endl;
    //cout << &cstring << endl;
    for(int i=0;i<length;i++) {
        cstring[i] = cstringIn[i];
    }
}

DSstring::DSstring(const DSstring & str) {
    //cout << "A DSstring with a value of " << str.cstring << " is gettign copied." << endl;
    length = str.length;
    cstring = new char[str.length + 1];
    int index = 0;
    while (str.cstring[index]) {
        //cout << "   attempting to add " << str.cstring[index] << " at index " << index << endl;
        cstring[index] = str.cstring[index];
        //cout << "   added " << cstring[index] << " at index " << index << endl;
        index++;
    }
    cstring[index] = 0;
    //cout << "The string got copied to a value of " << cstring << endl;
}

DSstring::DSstring() {
    cstring = NULL;
    length = 0;
}

char DSstring::charAt(int loc) {
    return cstring[loc];

}
DSstring& DSstring::operator= (const DSstring &str) {
    //cout << "A DSstring with a value of " << str.cstring << " is gettign assigned." << endl;
    length = str.length;
    cstring = new char[str.length + 1];
    int index=0;
    while (str.cstring[index]) {
        cstring[index] = str.cstring[index];
        index++;
    }
    cstring[index] = 0;
}

int DSstring::levDist(const DSstring& other) {
    return recursiveLevDist(length,other.length,other);
}

int DSstring::recursiveLevDist(int i, int j, const DSstring& other) {
    if(min(i,j) == 0) {
        return max(i,j);
    }
    
    int cost;
    if(charAt(i-1) == other.cstring[j-1]) {
        cost = 0;
    } else {
        cost = 1;
    }
    int a = recursiveLevDist(i-1,j,other)+1;
    int b = recursiveLevDist(i,j-1,other)+1;
    int c = recursiveLevDist(i-1,j-1,other)+cost;
    
    return min(min(a,b),c);

}

ostream& operator<<(ostream& os, const DSstring& dss) {
    os << dss.cstring;
    return os;
}
