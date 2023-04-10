//就是直接用队列完成层次遍历，但是这里要求每一层要分开，所以加两个current_num=0,next_num=0来统计当前层剩几个节点和下一层的节点数，用于更新depth

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        int current_num=0,next_num=0,depth=0;
        if(!root) return  {};
        current_num=1;
        q.push(root);
        res.push_back(vector<int>());
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            res[depth].push_back(temp->val);
            if(temp->left!=nullptr){
                q.push(temp->left);
                next_num++;
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
                next_num++;
            }
            current_num--;
            if(current_num==0){
                depth++;
                current_num=next_num;
                next_num=0;
                if(!q.empty()) res.push_back(vector<int>());
            }
        }


        return res;


    }
};
