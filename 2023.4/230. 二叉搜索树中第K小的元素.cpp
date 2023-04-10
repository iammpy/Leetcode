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
    int j=0,num=-1;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return -1;
        if(num!=-1) return num;
        kthSmallest(root->left ,  k);
        j++;
        if(k==j) num=root->val;
        kthSmallest(root->right, k);
        return num;
    }
};
