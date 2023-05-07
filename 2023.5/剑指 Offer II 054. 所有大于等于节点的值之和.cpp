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
    TreeNode* convertBST(TreeNode* root) {
        // 逆中序遍历
        // 这种需要用到上一个节点信息的问题，必须维护一个全局变量
        
        dfs(root);
        return root;


    }

int count=0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        
       dfs(root->right);
        count+=root->val;

        root->val=count;
        dfs(root->left);
        return root->val;
        
        
    }
};
