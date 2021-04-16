class Solution {
    public:
        vector<vector<char>> board_;
        int m;
        int n;
        int l;
        string word_;

        bool exist(vector<vector<char>>& board, string word) {
            m = board.size();
            if(m == 0) return word.empty();
            n = board[0].size();
            board_ = board;
            l = word.size();
            word_= word;
            bool ans = false;
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dfs(board, i, j, 0, vis, ans);
                    if(ans)
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        void dfs(board, int x, int y, int index, vector<vector<bool>> & vis, bool &ans)
        {
            if(index == l)
            {
                ans = true;
                return;
            }

            if(x < 0 || x >= m || y < 0 || y >= n || vis[x][y] == true || word[index] != board[x][y])
            {
                ans = false;
                return;
            }

            vis[x][y] = true;
            dfs(board, x+1, y, index+1, vis);
            dfs(board, x-1, y, index+1, vis);
            dfs(board, x, y+1, index+1, vis);
            dfs(board, x, y-1, index+1, vis);
            vis[x][y] = false;
        }
        
}
