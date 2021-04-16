class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int from = 0;
            int to = 0;
            int next_to = 0;
            while(from <= to)
            {
                while(from <= to)
                {
                    next_to = max(next_to, from + nums[from]);
                }

                if(next_to >= nums.size() - 1)
                {
                    return true;
                }

                from++;
                to = next_to;
            }

            return false;

                
        }
        
};
