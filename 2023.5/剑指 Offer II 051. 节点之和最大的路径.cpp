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
    int maxPathSum(TreeNode* root) {
        // dfs 每次找到从子节点的最大路径
        // 最大路径不经过根节点怎么办
        // 那需要维护一个最大路径的全局变量，用于判断最大路径
        if(!root) return 0;
        int leftmax=0,rightmax=0;
         if(root->left){
            leftmax=max(dfs(root->left),0);
        }
        if(root->right){
            rightmax=max(dfs(root->right),0);
        }    
        
        maxSum=max(maxSum,leftmax+rightmax+root->val);  
        return maxSum;



    }
private:
    int maxSum=INT_MIN;

    int dfs(TreeNode* root){

        int leftmax=0,rightmax=0;
        
        // 只有子节点返回的值是大于0才去使用，否则不选取这个子节点
        if(root->left){
            leftmax=max(dfs(root->left),0);
        }
        if(root->right){
            rightmax=max(dfs(root->right),0);
        }    
        
        maxSum=max(maxSum,leftmax+rightmax+root->val);
        return max(leftmax+root->val,rightmax+root->val);

    }

};
