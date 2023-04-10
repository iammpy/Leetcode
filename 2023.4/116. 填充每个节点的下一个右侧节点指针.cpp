//一个节点的信息不能满足next连接的需求，非同一个父节点的没法连接，需要传入两个节点，把遍历过程当作一个三叉树，每两个相邻节点当成一个三叉树的节点

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        traverse(root->left, root->right);
        return root;
    }
    void traverse(Node* left,Node* right){
        if(left==nullptr||right==nullptr){
            return ;
        }
        left->next=right;
        traverse(left->left,left->right);
        
        traverse(left->right,right->left);
        
        traverse(right->left,right->right);

    }
};
