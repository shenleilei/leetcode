class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            int ans = 0;
            int m = grid.size();
            if(m == 0) return 0;
            int n = grid[0].size();
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(grid[i][j] == '1')
                    {
                        ans++;
                        dfs(grid, i, j, m, n);
                    }
                }
            }
            
            return ans;
        }

        void dfs(vector<vector<char>>& grid, int x, int y, int m, int n)
        {
            if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0')
            {
                return;
            }

            grid[x][y] = '1';

            dfs(grid, x+1, y, m, n);
            dfs(grid, x-1, y, m, n);
            dfs(grid, x, y-1, m, n);
            dfs(grid, x. y+1, m, n);
        }
        
};
