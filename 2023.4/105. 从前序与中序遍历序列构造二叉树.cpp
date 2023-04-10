//类似于最大二叉树构建，

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
    int rootVal=0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        if(preorder.size()==0) return nullptr;
        construct(preorder, inorder, 0, inorder.size(), root);
        return root;

    }

    void construct(vector<int>& preorder, vector<int>& inorder,int l,int r,TreeNode*& root){
        int val=preorder[rootVal];
        int templ,tempr;
        for(int i=l;i<r;i++){
            if(inorder[i]==val){
                tempr=i;
                templ=tempr+1;
            }
        }
        root=new TreeNode(val);
        rootVal++;
        if(rootVal<preorder.size()){
            if(l<tempr){
                construct(preorder, inorder, l,tempr, root->left);
                
            }
        }
        if(rootVal<preorder.size()){
            if(templ<r){
                construct(preorder, inorder, templ,r, root->right);
                
            }
        }


    }
};
