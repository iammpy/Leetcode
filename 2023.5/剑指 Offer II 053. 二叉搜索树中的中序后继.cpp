/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        zhongxu(root, p);
        return found;
        
    }

    TreeNode* pre=nullptr;
    TreeNode* found=nullptr;



    void zhongxu(TreeNode* root,TreeNode* p){
        if(!root||found) return ;
        zhongxu(root->left,p);
        if(pre==p){
            found=root;
        }
        pre=root;
        zhongxu(root->right, p);
    }
};
