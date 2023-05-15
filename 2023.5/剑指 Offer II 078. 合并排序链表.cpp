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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 多路归并，使用一个堆保存每个数组的最小值以及对应的组，每提取一个就从对应数组中补充
        auto less=[&](ListNode* a,ListNode* b){
            return a->val>b->val;
        };

        priority_queue<ListNode*,vector<ListNode*>,decltype(less) > que(less);

        for(int i=0;i<lists.size();++i){
           if(lists[i]!=nullptr){
                que.push(lists[i]);
           }

        }
        ListNode* root=new ListNode(0);
        ListNode* node=root;
        while(!que.empty()){
            auto temp=que.top();
            que.pop();
            node->next=temp;
            node=node->next;
            if(temp->next!=nullptr) que.push(temp->next);

        }
        node->next=nullptr;

        return root->next;

    
    }
};
