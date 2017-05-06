#include <iostream>
#include <cstddef>
#include <fstream>
using namespace std;

int main()
{
    ifstream is ("input.txt", ifstream::binary);
    int length = is.tellg();
    char* buffer = new char [length];
    is.read (buffer,length);
    char* offset = buffer;
    unsigned char c;
    for(int i = 0; i < length; ++i) cout << buffer[i];
    //while(c = *offset++) {
        //cout << hex << (int)c << ' ';
        //if(c < 128) {
            //cout << (char)c;
        //} else if(c >= 0x90 && c <= 0x9f) { // array
            //cout << (int)(c & 15);
            //cout << " array";
        //} else if(c >= 0xa0 && c <= 0xbf) { // string
            //cout << (bitset<8>)c;
            ////cout << (int)(c & 31);
            //cout << " string";
        //} else {
            //cout << (char)c;
        //}
        //cout << endl;
    //}
    delete[] buffer;
    return 0;
}

