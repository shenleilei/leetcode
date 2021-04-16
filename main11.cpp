
vector<vector<int>> permute(vector<int>& nums) {
    int l = nums.size();

    vector<vector<int>> ans;
    vector<bool> vis(l, false);
    
    dfs(nums, 0, line, ans, vis);

    return ans;

}

void dfs(vector<int>& nums, int start, vector<int> line, vector<vector<int>> & ans, vector<bool> vis)
{
    if(line.size() == nums.size()) 
    {
        ans.push_back(line);
        return;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(vis[i] == false)
        {
            vis[i] = true;
            line.push_back(nums[i]);
            dfs(nums, i+1, line, ans);
            line.pop_back();
            vis[i] = false;
        }
    }
}
