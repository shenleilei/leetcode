//#include<string>
#include<iostream>
#include <string.h>

using namespace std;

int main()
{
    string s = "hello, world";
    cout << s.capacity() << " " << s.size() << endl;
    char *src = "world, hello";
    strcat((char*)s.c_str(), src);
    cout << s << " " << s.size() << endl;
}
