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
    // TreeNode* root
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root;
        if(nums.size()>0) construct(nums, 0, nums.size(), root);
        return root;

    }

    void construct(vector<int>& nums,int l,int r,TreeNode*& root){

        int maxNum=INT_MIN;
        int templ,tempr;
        for(int i=l;i<r;i++){
            if(maxNum<nums[i]){
                maxNum=nums[i];
                tempr=i;
            }
        }
        templ=tempr+1;
        root=new TreeNode(maxNum);
        if(l<tempr) construct(nums, l, tempr, root->left);
        if(templ<r) construct(nums,templ,r,root->right);

    }
};
