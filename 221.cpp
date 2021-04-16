class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int ans = 0;
            auto row = matrix.size();
            if(row == 0) return 0;
            auto col = matrix[0].size();
            
            vector<vector<int>> dp(row, vector<int>(col, 0));

            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < col; j++)
                {
                    if(matrix[i][j] == '1')
                    {
                        if(i > 0 && j > 0)
                        {
                            dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                        }
                        else
                        {
                            dp[i][j] = 1; 
                        }

                        ans = max(dp[i][j], ans);
                    }
                }
            }

            return ans * ans;
        }
};
