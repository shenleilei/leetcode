class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            dfs(candidates, target, 0, {}, ans);
            return ans;
                
        }

        void dfs(vector<int>& candidates, int target, int start, vector<int> line, vector<vector<int>> & ans)
        {
            if(target == 0)
            {
                ans.push_back(line);
                return 0;
            }
            if(target < 0)
            {
                return 0;
            }

            for(int i = start; i < candidates.size(); i++)
            {
                line.push_back(candidates[i]);
                int ret = dfs(candidates, target - candidates[i], i, line ,ans);
                line.pop_back();
                if(ret == 0)
                {
                    break;
                }
            }

            return -1;
        }
        
};
