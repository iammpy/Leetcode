/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return nullptr;
        ListNode* root =new ListNode(0);
        root->next=head;
        ListNode* slow=root->next,*fast=root->next->next;
        while(slow&&fast){
            if(slow==fast) break;
            if(fast->next!=nullptr)fast=fast->next->next;
            else break;
            slow=slow->next;
        }
        if(!slow||!fast||slow!=fast) return nullptr;
        
        ListNode* slowslow=root;
        // int pos=0;
        while(slowslow!=slow){
            slow=slow->next;
            slowslow=slowslow->next;
            // pos++
        }

        return slowslow;

        
    }
};
