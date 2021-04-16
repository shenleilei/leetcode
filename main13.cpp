#include<limits.h>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
    public:
        bool all_has(unordered_map<char, int> & d_s, unordered_map<char, int> & d_t)
        {
            bool all = true;
            for(auto c : d_t)
            {
                if(d_s.find(c.first) == d_s.end() || d_s[c.first] < d_t[c.first])
                {
                    all = false;
                    break;
                }
            }

            return all;
        }

        string minWindow(string s, string t) {
            int len_s = s.size();
            int len_t = t.size();
            int l = 0; int r = 0;
            int start = 0; int size = INT_MAX;
            unordered_map<char, int> d_s;
            unordered_map<char, int> d_t;

            for (int i = 0; i < len_t; i++)
            {
                if(d_t.count(t[i]) == 0)
                {
                    d_t[t[i]] = 1;
                }
                else
                {
                    d_t[t[i]]++;
                }
            }

            while(r < len_s)
            {
                if(d_s[s[r]] != 0)
                {
                    d_s[s[r]]++;
                }
                else
                {
                    d_s[s[r]] = 1;
                }

                while(l <= r && all_has(d_s, d_t))
                {
                    if(size > (r - l + 1))
                    {
                        start = l;
                        size = (r - l + 1);

                        if(size == len_t)
                        {
                            return s.substr(start, size);
                        }
                    }

                    d_s[s[l]]--;
                    if(0 == d_s[s[l]])
                    {
                        d_s.erase(s[l]);
                    }
                    if(l < r)
                    {
                        l++;
                    }
                }

                r++;
            }

            return size == INT_MAX ? "" : s.substr(start, size);
        }
};

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC");
}
