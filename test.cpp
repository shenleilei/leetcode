#include<unordered_map>
#include<map>
#include<iostream>

using namespace std;

int main()
{
    unordered_map<int, int> m = {{1,2},{3,4}};
    cout << m[1] << " " << m[5] << endl;
    map<int, int> k = {{1,2}, {3,4}};
    cout << k[1] << " " << k[5] << endl;
}
