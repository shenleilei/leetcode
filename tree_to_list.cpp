class Solution {
    public:
        void flatten(TreeNode* root) {
            while(root)
            {
                auto left = root->left;
                auto right = root->right;

                if(!left)
                {
                    root = root->right;
                }
                else
                {
                    root->right = left;
                    root->left = nullptr;
                    
                    while(left->right)
                    {
                        left = left->right;
                    }

                    left->right = right;

                    root = root->right;
                }
            }
                
        }
        
};
