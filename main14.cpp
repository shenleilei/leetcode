#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4};
    int l = 1;
    vec.erase(remove_if(vec.begin(), vec.end(), [=](const int & item) { return item == l; }), vec.end());
    for(auto item : vec)
    {
        cout << item << endl;
    }
}
