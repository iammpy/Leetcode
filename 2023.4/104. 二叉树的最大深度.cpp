//进入节点时增加深度，离开节点时减小深度


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res=1 ,m=0;
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr&&root->right==nullptr){
            m=max(res,m);
        }


        res++;
        maxDepth(root->left);
        maxDepth(root->right);
        res--;
        return m;
    }
    
};
