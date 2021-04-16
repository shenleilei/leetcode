class Solution {
    public:
        int kthSmallest(TreeNode* root, int k) {
            int ans;
            traverse(root, k, ans);
            return ans;
        }

        void traverse(TreeNode* root, int k, int &ans)
        {
            traverse(root->left, k, ans);
            if(--k == 0)
            {
                ans = root->val; return;
            }
            traverse(root->right, k, ans);
        }
};
