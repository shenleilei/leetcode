class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& matrix) {
            int l = matrix.size();
            if (l == 0 || l == 1) return matrix;
            
            for(int i = 0; i < l; i++)
            {
                for(int j = 0; j < l; j++)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }

            return matrix;
        }
        
};
