#include<vector>
#include<iostream>
#include<deque>
using namespace std;

vector<int> sliceWindow(vector<int> & nums, int k)
{
    vector<int> ans;
    deque<int> window;
    for(int i = 0; i < k; i++)
    {
        while(!window.empty() && nums[window.back()] < nums[i])
        {
            window.pop_back();
        }
        window.push_back(i);
    }

    ans.push_back(nums[window.front()]);
    const int l = nums.size();
    for(int i = k; i < l; i++)
    {
        if(window.size() == k) window.pop_front();
        while(!window.empty() && nums[window.back()] < nums[i])
        {
            window.pop_back();
        }
        window.push_back(i);
        ans.push_back(nums[window.front()]);
    }

    return ans;
}


int main()
{
    vector<int> nums = {-3,1,-2,4};
    vector<int> ans = sliceWindow(nums, 2);
    for(auto num : nums){
        cout << num << " " ;
    }
    cout << endl;
    for(auto num : ans){
        cout << num << " " ;
    }
    return 0;
}
