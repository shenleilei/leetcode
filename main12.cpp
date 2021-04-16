class Solution {
    public:
        uint64_t hash(const string & str)
        {
            int val;
            for(const auto c : str)
            {
                val += (c - 'a') * (c - 'a' - 1) / 2 ;
            }

            return val;
        }

        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<int, vector<string>> d;
            vector<vector<string>> ans;

            for(const auto & str : strs)
            {
                int h_v = hash(str);
                d[h_v].push_back(str);
            }

            for(const auto item : d)
            {
                ans.push_back(item.second);
            }
                
            return ans;
        }
        
};
