// 就是正常的层次遍历去构造以及读取二叉树，主要是对于null的处理方式

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res="";
        // res+="abc";
        queue<TreeNode*> que; 
        // 什么时候需要加null，什么时候不需要加入null
        //null全都加上，最后对字符串进行处理，去掉末尾的null
        //或者增加一个缓冲字符串，出现null先暂存到缓冲串中，当后面出现数字再一起加入到主串中
        que.push(root);
        string tem="";
        while(!que.empty()){
            TreeNode* node=que.front();
            que.pop();
            if(node==nullptr){
                tem+="null,";
                continue;
            }else{
                que.push(node->left);
                que.push(node->right);
                tem=tem+to_string(node->val)+",";
                res+=tem;
                tem="";
            }
        }



        // 删除结尾的逗号
        // return "abc";
        if(res.size()>0){
            res.erase(res.size()-1,1);
        }
        return res;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        int l=0;
        
        data+=",";
        int r=data.find(',');
        queue<TreeNode*> que;
        TreeNode* root=new TreeNode(0);
        que.push(root);
        int chooseleft=1;
        

        while(r<data.size()){
            // ii=ffidfsfasdfa
            string str=data.substr(l,r-l);
            if(str=="null"){
                // chooseleft=()chooseleft+1)%2;
                if(chooseleft==0){
                    chooseleft=1;
                }else if(chooseleft=1){
                    chooseleft=0;
                    que.pop();
                }
                // continue;

            }else{
            int val=stoi(str);
            TreeNode* tre=que.front();
            if(chooseleft==0){
                tre->left=new TreeNode(val);
                que.push(tre->left);
                chooseleft=1;
            }else if(chooseleft==1){
                tre->right=new TreeNode(val);
                que.push(tre->right);
                chooseleft=0;
                que.pop();


            }
            }
            
            


            l=r+1;
            r=data.find(',',l);
        }
        return root->right;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
