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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int current;
        int carry=0;
        ListNode* res=new ListNode(-1);
        ListNode* p=res;
        while(l1!=nullptr||l2!=nullptr){
            int x= l1==nullptr?0:l1->val;
            int y= l2==nullptr?0:l2->val;
            int sum=x+y+carry;
            current=sum%10;
            carry=sum/10;
            p->next=new ListNode(current);
            p=p->next;
            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;

        }

        if(carry==1){
            p->next=new ListNode(carry);
        }




        return res->next;

    }
};
