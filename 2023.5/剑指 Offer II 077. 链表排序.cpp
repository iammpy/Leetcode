// 冒泡法，超时

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
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* root=new ListNode(INT_MIN,head);
        ListNode* l=root,*r=root->next;
        int n=0;
        while(r!=nullptr){
            if(l->val>r->val){
                int temp=r->val;
                r->val=l->val;
                l->val=temp;

            }
            l=l->next;
            r=r->next;
            ++n;
        }
        for(int i=0;i<n;++i){
            l=root;
            r=root->next;
            for(int j=0;j<n-i;++j){
                if(l->val>r->val){
                int temp=r->val;
                r->val=l->val;
                l->val=temp;

            }
            l=l->next;
            r=r->next;

            }
        }
        


        return root->next;


    }
};
