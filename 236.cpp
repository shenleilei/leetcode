class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // 1.先序遍历找到路径                  
            vector<TreeNode*> path_1;
            vector<TreeNode*> path_2;

            preOrder(root, p, path_1);
            preOrder(root, q, path_2);
            
            auto iter_1 = path_1.begin();
            auto iter_2 = path_2.begin();
            auto pre = iter_1;
            while(iter_1 != path_1.end() && iter_2 != path_2.end())
            {
                if(*iter_1 != *iter_2)
                {
                    break;
                }
                else
                {
                    pre = iter_1;
                    iter_2++;
                    iter_1++;
                }
            }

            return *pre;
                
        }

        bool preOrder(TreeNode* root, TreeNode* target, vector<TreeNode*> & path)
        {
            if(!root)
            {
                return false;
            }

            if(root == target)
            {
                path.push_back(root);
                return true;
            }
            
            else
            {
                path.push_back(root);
                bool ret = preOrder(root->left, target, path);
                if(ret == true)
                {
                    return true;
                }
                ret = preOrder(root->right, target, path);
                if(ret == true)
                {
                    return true;
                }
                path.pop_back();
            }

            return false;

        }
        
};
