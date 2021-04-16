class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {
            stack<int> s;
            int l = T.size();
            if(l == 0) return {};

            vector<int> ans(l, -1);
            for(int i = 0; i < l; i++)
            {
                while(!s.empty() && T[i] > T[s.top()])
                {
                    ans[s.top()] = T[i];
                    s.pop();
                }
                s.push(i);
            }
                

            return ans;
        }
        
};
