class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            auto l = intervals.size();
            if(l == 0) return vector<vector<int>>{newInterval};

            vector<vector<int>> ans;

            int i = 0;
            while(i < l)
            {
                if(intervals[i][1] < newInterval[0])
                {
                    break;
                }

                ans.push_back(intervals[i]);
                i++;
            }

            auto left = newInterval[0];
            auto right = newInterval[1];

            left = min(intervals[i][0], left);

            int j = i;
            while(j < l)
            {
                if(intervals[j][0] <= right)
                {
                    right = max(right, intervals[j][1])
                    j++;
                }
                
            }

            ans.push_back(vector<int>{left, right});

            while(j < l)
            {
                ans.push_back(intervals[j]);
            }

            return ans;
        }
        
};
