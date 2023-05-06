// 递归，从最底层开始剪，判断达到最底层时，并且值为0时，返回null，让上一层指向null

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
public:
    TreeNode* pruneTree(TreeNode* root) {



        if(root->left){
            TreeNode* tre= pruneTree(root->left);
            root->left=tre;
        }
        if(root->right){
             TreeNode* tre=pruneTree(root->right);
             root->right=tre;
        }
        if(!root->left&&!root->right&&root->val==0){
            return nullptr;
        }
        return root;

    }
};
