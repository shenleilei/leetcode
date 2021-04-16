#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<string> candidates;
    string str;
    vector<string> ans;

    vector<string> word_search(vector<string> candidates_, string str_)
    {
        candidates = candidates_;
        str = str_;

        vector<string> vec;
        word_search2(0, vec);

        return ans;
    }

    bool in_vec(string s)
    {
        for(auto item : candidates)
        {
            if(item == s)
            {
                return true;
            }
        }

        return false;
    }

    void word_search2(int from, vector<string> vec)
    {
        if(from == str.size())
        {
            if(vec.size() < ans.size() || ans.empty())
            {
                ans = vec;
            }
        }

        for(int i = from; i < str.size(); i++)
        {
            auto sub = str.substr(from, i - from + 1);
            
            if(in_vec(sub))
            {
                vec.push_back(sub);
                word_search2(i + 1, vec);
                vec.pop_back();
            }
        }
    }

};


int main()
{
    Solution s;
    auto ans = s.word_search({"ali", "a", "b", "li", "baba"}, "alibaba");
    for(const auto & item : ans)
    {
        cout << item << endl;
    }
}


