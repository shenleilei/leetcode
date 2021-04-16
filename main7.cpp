#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val_) : val(val_), left(nullptr), right(nullptr){}
};

class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> p_d;
            unordered_map<int, int> i_d;
            int p_l = preorder.size(); int i_l = inorder.size();
            for(int i = 0; i < p_l; i++)
            {
                p_d[preorder[i]] = i;
            }

            for(int i = 0; i < i_l; i++)
            {
                i_d[inorder[i]] = i;
            }
            
            return buildTree(preorder, p_d, inorder, i_d, 0, p_l - 1);
        }

        TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int> & p_d,
                vector<int>& inorder, unordered_map<int, int> i_d, int start, int end)
        {
            if(start > end) return nullptr;
            if(start == end) return new TreeNode(inorder[start]);

            int min_i_index = INT_MAX; int min_p_index = INT_MAX;
            for(int i = start; i <= end; i++)
            {
                auto value = inorder[i];
                if(p_d[value] < min_p_index)
                {
                    min_p_index = p_d[value];
                    min_i_index = i;
                }
            }

            TreeNode* root = new TreeNode(inorder[min_i_index]);
            root->left = buildTree(preorder, p_d, inorder, i_d, start, min_i_index - 1);
            root->right = buildTree(preorder, p_d, inorder, i_d, min_i_index + 1, end)
            
            return root;
        }

};

int main()
{

}



