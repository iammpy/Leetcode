// k个一组，找到pre，left，right，suc 然后进行翻转操作和拼接，直到剩下的不足k个元素

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy,*left=pre->next,*right,*suc;
        while(pre->next!=nullptr){
            left=pre->next;
            right=pre;
          //用于判断剩余元素是否能形成一组
            bool complete=false;
            for(int i=0;i<k;i++){
                if(right->next!=nullptr){
                    right=right->next;
                    if(i==k-1) complete=true;
                }

            
            }
            if(complete) {
                suc=right->next;
                right->next=nullptr;
                reverseN(left);
                pre->next=right;
                left->next=suc;
                pre=left;
                // left=suc;
            }else{
                break;
            }



        }
        return dummy->next;
        
        
    }
};
