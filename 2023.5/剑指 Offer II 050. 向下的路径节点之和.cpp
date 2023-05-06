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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        // 不要忘记添加hash[0], 代表在前面添加一个为0的节点，不然后面前缀和恰好等于target的节点无法判断
        hash[0]=1;
        dfs(root,targetSum,0);
        


        return count;

    }


private:
    int count=0;
    // 哈希表中存放前缀和以及对应出现的次数
    unordered_map<long long,int> hash;

    void dfs(TreeNode* root, int targetSum,long long prefixSum){
        prefixSum+=root->val;
        if(hash.find(prefixSum-targetSum)!=hash.end()){
            count+=hash[prefixSum-targetSum];
        }

        hash[prefixSum]++;
        if(root->left){
            dfs(root->left,targetSum,prefixSum);
        }
        if(root->right){
            dfs(root->right,targetSum,prefixSum);
        }

        hash[prefixSum]--;
    }
};
