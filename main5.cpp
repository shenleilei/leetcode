#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void getMax(vector<int> & vec, int start, int end, int k, int line, int & ans)
{
    if (k == 0) 
    {
        ans = max(ans, line);    
        return;
    }
    getMax(vec, start + 1, end, k-1, line + vec[start], ans);
    getMax(vec, start, end - 1, k-1, line + vec[end] , ans);
}

int getMax(vector<int> & vec, int k)
{
    int ans = 0;
    int start = 0;
    int end = vec.size() - 1;
    getMax(vec, start, end, k, 0, ans);
    return ans;
}


int main()
{
    vector<int> vec = {3,4,-1,-2, 1,8,0};
    cout << getMax(vec, 3);
}
