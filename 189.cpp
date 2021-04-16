/**
 *  [1,2,3,4,5,6,7] k = 3
 *  [7,6,5,4,3,2,1] 全部翻转
 *  [5,6,7,4,3,2,1] 翻转全K个
 *  [5,6,7,1,2,3,4] 翻转后N-K个
 */

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k, nums.end());
        }

};
