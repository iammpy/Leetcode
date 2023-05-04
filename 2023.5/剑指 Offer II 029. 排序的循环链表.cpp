/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head) {
            head=new Node(insertVal);
            head->next=head;
            return head;
        }
        Node* root=new Node(INT_MAX);
        root->next=head;
        Node* fast=head->next,*slow=head;
        while(true){
            if(slow!=root&&(fast->val<slow->val&&(insertVal>slow->val||insertVal<=fast->val))||(fast->val>=slow->val&&insertVal>=slow->val&&fast->val>=insertVal)){

            slow->next=new Node(insertVal);
            slow->next->next=fast;

            return root->next;  
            }
            slow=slow->next;
            fast=fast->next;
            if(fast==head){
                 slow->next=new Node(insertVal);
            slow->next->next=fast;

            return root->next;  
            }

        }



        return root->next;
        
    }
};
