// 搜索旋转数组的最小值
class Solution {
    public:
        int findMin(vector<int>& nums) {
            int len = nums.size();
            if(len == 1) return nums[0];
            int l = 0; int r = len - 1;
        
            while(l <= r)
            {
                int mid = l + (r - l) / 2;
                if(mid == 0 && nums[mid] < nums[mid + 1] 
                        || mid == len - 1 && nums[mid] < nums[mid - 1]
                        || nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1] )
                {
                    return nums[mid];
                }
                
                if(nums[0] < target)
                {
                    if(target < nums[mid])
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }

                    continue;
                }
                else
                {
                    if(target > nums[mid])
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }

            }

            return -1;
                
        }
        
};
