// 破题关键在要从【四条边】开始搜索
class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int m = board.size();
            if(m == 0) return;
            int n = board[0].size();
            
            for(int i = 0; i < m; i++)
            {
                dfs(board, i, 0);
                dfs(board, i, n-1);
            }

            for(int j = 0; j < n; j++)
            {
                dfs(board, 0, j);
                dfs(board, n-1, j);
            }

            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(board[i][j] == 'S')
                    {
                        board[i][j] = 'O';
                    }

                    if(board[i][j] == 'O')
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }

        void dfs(vector<vector<char>>& board, int x, int y)
        {
            if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
            {
                return;
            }

            board[x][y] = 'S';
            dfs(board, x-1, y);
            dfs(board, x+1, y);
            dfs(board, x, y-1);
            dfs(board, x, y+1);
        }
};


