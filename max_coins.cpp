#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<int> coins;
    int k;
    int ans = 0;
    
    int max_value(const vector<int> & coins_, int k_ ) 
    {
        coins = coins_;
        k = k_;
        max_value2(0, coins.size() - 1, 0, k);
        return ans;
    }

    void max_value2(int l, int r, int v, int k)
    {
        if(k == 0)
        {
            ans = max(ans, v);
            return;
        }

        max_value2(l+1, r, v + coins[l], k - 1);
        max_value2(l, r-1, v + coins[r], k - 1);
    }
};


int main()
{
    Solution s;
    cout << s.max_value({5,7,4,1,1,3,2}, 4) << endl;
}

