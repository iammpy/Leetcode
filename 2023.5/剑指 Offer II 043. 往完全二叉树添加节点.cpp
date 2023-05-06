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
class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> que;
    
public:
    CBTInserter(TreeNode* root) {
        TreeNode* head=new TreeNode(0);
        head->left=new TreeNode(0);
        que.push(head);
        queue<TreeNode*> ini;
        ini.push(root);
        while(!ini.empty()){
            TreeNode* tr=ini.front();
            ini.pop();
            //插入到新的树中；
            int val=tr->val;
            TreeNode* tre2= que.front();
            if(!tre2->left){
                tre2->left=new TreeNode(val);
                que.push(tre2->left);
            }else{
                tre2->right=new TreeNode(val);
                que.pop();
                que.push(tre2->right);
            }
            
            if(tr->left){
                ini.push(tr->left);
            }
            if(tr->right){
                ini.push(tr->right);
            }
        }
        this->root=head->right;
        

    }
    
    int insert(int v) {
        //插入到新的树中；
            int res;
            TreeNode* tre2= que.front();
            if(!tre2->left){
                tre2->left=new TreeNode(v);
                que.push(tre2->left);
                
            }else{
                tre2->right=new TreeNode(v);
                que.pop();
                que.push(tre2->right);
            }

            return tre2->val;



    }
    
    TreeNode* get_root() {
        return root;


    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
