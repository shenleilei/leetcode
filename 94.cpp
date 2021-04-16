class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode*> st;
            while(root)
            {
                st.push(root);
                root = root->left;
            }

            while(!st.empty())
            {
                auto top = st.top();
                st.pop();
                ans.push(top->val);
                root = top->right;
                while(root)
                {
                    st.push(root);
                    root = root->left;
                }
            }

            return ans;
                
        }
        
};
