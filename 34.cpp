/*
 * 在排序数组中搜索目标元素的第一个和最后一个索引位置
 * [1,2,3,4,4,5,6] target = 4; 返回[3,4]
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        auto l = 0; 
        auto r = nums.size() - 1;
        
        auto left = find_left(nums, target, l, r);
        auto right = find_right(nums, target, l, r);
    
        return {left, right};
    }
    
    int find_left(const vector<int> & nums, int target, int l, int r)
    {
        auto ans = -1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                ans = mid;
                r = mid - 1;
                continue;
            }
            if(nums[mid] > target)
            {
                r = mid - 1;
                continue;
            }
            if(nums[mid] < target)
            {
                l = mid + 1;
            }
        }

        return ans;
    }
    
    int find_right(const vector<int> & nums, int target, int l, int r)
    {
        int ans = -1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                ans = mid;
                l = mid + 1;
                continue;
            }
            if(nums[mid] > target)
            {
                r = mid - 1;
                continue;
            }
            if(nums[mid] < target)
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};














