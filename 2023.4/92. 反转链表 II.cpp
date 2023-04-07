/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverseN(ListNode* head){
        if(!head||!head->next) return head;
        ListNode *pre,*cur;
        pre=nullptr;
        cur=head;
        while(cur!=nullptr){
            ListNode* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return  pre;


    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //设置虚节点，找到需要反转的子链表，调用链表翻转函数，拼接整个链表
        ListNode *pre,*suc,*leftNode,*rightNode,*cur;
        ListNode*root=new ListNode(-1);
        root->next=head;
        cur=root;
        for(int i=0;i<left-1;i++){
            cur=cur->next;
        }

        pre=cur;
        
        leftNode=cur->next;
        for(int i=0;i<right-left+1;i++){
            cur=cur->next;
        }
        rightNode=cur;
        suc=cur->next;
        // return suc;
        rightNode->next=nullptr;
         reverseN(leftNode);
        //  return pre;

        pre->next=rightNode;
        // return leftNode;
        leftNode->next=suc;
        return root->next;

        




    }
};
