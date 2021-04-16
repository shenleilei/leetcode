class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int l = nums.size();
            if(l == 0) return 0;

            vector<vector<int>> min_vec(l, vector<int>(l, 0));
            vector<vector<int>> max_vec(l, vector<int>(l, 0));

            min_vec[0][0] = max_vec[0][0] = nums[0];

            int ans = nums[0];

            for(int i = 0; i < l; i++)
            {
                for(int j = i; j > 0 && j < l; j++)
                {
                    if(nums[j] < 0)
                    {
                        min_vec[i][j] = max[i][j-1] * nums[j];
                        max_vec[i][j] = min[i][j-1] * nums[j];
                    }
                    else
                    {
                        if(nums[j] == 0)
                        {
                            min_vec[i][j] = max_vec[i][j] = 0;
                        }
                        else
                        {
                            max_vec[i][j] = max[i][j-1] * nums[j];
                            min_vec[i][j] = min[i][j-1] * nums[j];
                        }
                    }
                    ans = max(ans, max_vec[i][j]);
                }
            }

            return ans;
        }
        
};
