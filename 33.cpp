class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int l = 0;
            int r = nums.size() - 1;
            auto first = nums[0];
            auto last = nums[r];

            while(l < r)
            {
                int mid = (l + r) / 2;
                if(nums[mid] == target)
                {
                    break;
                }
                if(nums[mid] < last)
                {
                    if(nums[mid] < target && target <= last)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
                else
                {
                    if(target >= first && target < nums[mid])
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }

            return nums[l] == target ? l : -1;
                
        }
        
};
