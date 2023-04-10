//使用反着的前序遍历（不是后序），相当于从后向前，在后面将当前节点的指针指向next，并将当前的指针存储为next，供他前面的节点调用

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
    TreeNode* pre,*next=nullptr;
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return ;
        flatten(root->right);
        flatten(root->left);
        root->right=next;
        root->left=nullptr;
        next=root;
        

    }
};
