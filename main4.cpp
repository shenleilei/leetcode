/* 搜索旋转数组最小值
 * [5,6,7,8,1,2,4]
 * 返回最小值1
 * */

int findMin(vector<int>& nums)
{
    int l = nums.size();
    if(l == 1) return nums[0];

    if(nums[l-1] > nums[0]) return nums[0];

    int left = 0; int right = l-1;
    while(left <= right)
    {
        int mid = left + (right - left) >> 1;
        if(nums[mid] > nums[mid+1]) 
        {
            return nums[mid+1];
        }
        if(nums[mid] < nums[mid-1])
        {
            return nums[mid];
        }

        if(nums[0] < nums[mid])
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }

    return -1;
}










