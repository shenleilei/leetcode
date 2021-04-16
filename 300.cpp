class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int l = nums.size();
            if(l == 0) return 0;
            
            vector<int> dp(l, 1);
            int ans = 1;

            for(int i = 1; i < l; i++)
            {
                for(int j = 0; j < i; j++)
                {
                    if(nums[i] > nums[j] && dp[i] < (dp[j] + 1))
                    {
                        dp[i] = (dp[j] + 1);
                        ans = max(ans, dp[i]);
                    }
                }
            }

            return ans;
        }
};
