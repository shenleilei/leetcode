class Solution {
    public:
        int l;
        vector<int> prices_;
        int maxProfit(vector<int>& prices) {
            l = prices.size();
            if(l < 2) return 0;
            prices_ = prices;

            return maxProfit(0, INT_MAX);

        }

        int maxProfit(int i, int min_value)
        {
            if(i >= l)
            {
                return 0;

            }

            int profit1 = prices_[i] - min(min_value, prices_[i]) + maxProfit(i+2, INT_MAX);
            int profit2 = maxProfit(i + 1, min(min_value, prices_[i]));

            return max(profit1, profit2);

        }

};
