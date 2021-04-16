class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
           int l = nums.size();
           i = l - 1;
           while(i > 0 && nums[i-1] >= nums[i])
           {
               i--;
           }

           sort(nums.begin() + i, nums.end());
           
           if(i == 0)
           {
               return;
           }

           int j = i;
           while(j < l)
           {
               if(nums[j] > nums[i-1])
               {
                   swap(nums[i-1], nums[j]);
                   return;
               }
           }
                
        }
};
