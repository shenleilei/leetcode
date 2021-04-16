class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            bool ans = true;
            treeHeight(root, ans);
            return ans;
        }

        int treeHeight(TreeNode* root, bool & ans)
        {
            if(!root || !ans)
            {
                return 0;
            }
            
            int l_h = treeHeight(root->left);
            int r_h = treeHeight(root->right);
            if(abs(l_h - r_h) > 1) 
            {
                ans = false;
            }
            return max(l_h, r_h) + 1;
        }
};
