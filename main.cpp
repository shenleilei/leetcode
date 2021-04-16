#include<iostream>
using namespace std;

void check_param()
{
    cout << "valid" << endl;
}

template<class T, class ... Args>
void check_param(T&& first, Args&& ... last)
{
    if (!first)
    {
        cout << "is null" << endl;
        return;
    }
    else
    {
        check_param(last...);

    }

}


int main()
{
    char* s = "helloworld";
    char* d = "worldhello";
    check_param(s, d, nullptr);
}
