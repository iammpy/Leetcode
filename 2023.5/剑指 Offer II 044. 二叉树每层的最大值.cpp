// 相比于通常的层次遍历，在队列中除了节点指针之外还添加了这个节点的深度信息，用于判断当前节点层次

// res.size返回是一个无符号数，不能用res。size-1用作判断条件



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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<pair<TreeNode*,int>> que;
        que.push(make_pair(root,0));
        while(!que.empty()){
            TreeNode* node=que.front().first;
            int depth=que.front().second;
            que.pop();
            if(node->left){
                que.push(make_pair(node->left,depth+1));
            }
            if(node->right){
                que.push(make_pair(node->right,depth+1));
            }
            if(depth+1>res.size()){
                res.push_back(INT_MIN);
            }
            res[depth]=max(res[depth],node->val);
            
        }



        return res;


    }
};
