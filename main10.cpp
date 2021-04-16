#include<vector>
#include<iostream>
#include<dequeue>
using namespace std;

vector<int> slideWindow(vector<int> & nums, int k)
{
    const auto l = nums.size();
    vector<int> ans;
    if(k > l) return ans;

    deque<int> window;
    for(int i = 0; i < k; i ++)
    {
        while(!window.empty() && nums[window.back()] < nums[i])
        {
            window.pop_back();
        }
        window.push_back(i);
    }

    ans.push_back(nums[window.front()]);

    for(int i = k; i < l; i++)
    {
        if(!window.empty() && (i - window.front() == k))
        {
            window.pop_front();
        }

        while(!window.empty() && nums[window.back()] < nums[i])
        {
            window.pop_back();
        }

        window.push_back(i);
        ans.push_back(nums[window.front()]);
    }

    return ans;

}
