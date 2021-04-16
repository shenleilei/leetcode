class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int l = heights.size();
            if(l == 0) return 0;

            int ans = heights[0];
            stack<int> s;
            s.push(0);

            for(int i = 1; i < l; i++)
            {
                while(!s.empty() && heights[s.top()] > heights[i])
                {
                    auto top = s.top();
                    ans = max(ans, heights[top] * (i - top));
                }
                s.push(i);
            }

            while(!s.empty())
            {
                auto top = s.top();
                ans = max(ans, heights[top] * (i - top));
                s.pop();
            }

            return ans;
        }
        
};
