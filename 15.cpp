class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ans;
            int l = nums.size();
            sort(nums.begin(), nums.end());

            for(int i = 0; i < l; i++)
            {
                if(i > 0 && nums[i] == nums[i-1])
                {
                    continue;
                }

                auto target = -nums[i];
                
                auto left = i + 1;
                auto right = l - 1;
                while(left < right)
                {
                    auto delta = nums[left] + nums[right] - target;
                    if(delta == 0)
                    {
                        ans.push_back({-target, nums[left], nums[right]});

                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l+1])
                        {
                            l++;
                        }
                        while(l < r && nums[r] == nums[r-1])
                        {
                            r--;
                        }
                    }
                    else
                    {
                        if(delta > 0)
                        {
                            r--;
                        }
                        else
                        {
                            l++;
                        }
                    }
                }

            }

            return ans;
        }
        
};
