class Solution {
    public:
        vector<vector<int>> ans;
        vector<vector<int>> levelOrder(TreeNode* root) {
            if(!root) return ans;
            queue<TreeNode*> next_q;
            next_q.push(root);
            
            while(!next_q.empty())
            {
                auto q = move(next_q);
                while(!q.empty())
                {
                    auto top = q.top();
                    q.pop();
                    line.push(top->val);
                    if(line->left) next_q.push(line->left);
                    if(line->right) next_q.push(line->right);
                }
                ans.push_back(line);
            }

            return ans;
        }

};
