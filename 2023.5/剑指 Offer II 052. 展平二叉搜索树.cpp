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
    TreeNode* increasingBST(TreeNode* root) {
        // 中序遍历
        if(!root) return nullptr;
        zhongxu(root);
        return head;




    }
    TreeNode* pre=nullptr;
    TreeNode* head=nullptr;
    void zhongxu(TreeNode* root){
        if(!root) return;

        zhongxu(root->left);
        if(pre){
            pre->right=root;
            pre->left=nullptr;
        }
        pre=root;
        root->left=nullptr;
        if(!head) head=root;
        zhongxu(root->right);
        // root->left=nullptr;
        // root->right=nullptr;

        
        


    }
};
