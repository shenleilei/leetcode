class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            return isValidBST(root, INT_MIN, INT_MAX);
        }


        bool isValidBST(TreeNode* root, int min_val, int max_val)
        {
            if(!root) 
            {
                return true;
            }

            if(root->val >= max_val || root->val <= min_val)
            {
                return false;
            }

            return isValidBST(root->left, min_val, root->val) && isValidBST(root->right, root->val, max_val);
        }
        
};
