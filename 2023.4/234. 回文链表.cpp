//利用函数递归来模拟堆栈，模仿树的后序遍历，再利用一个全局变量从前往后的指针来进行比较

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

    ListNode * left;
    bool tr(ListNode* right){
        if(right==nullptr) return true;
        bool res=tr(right->next);
        res=res&&(left->val==right->val);
        left=left->next;
        return res;
    }

public:
    bool isPalindrome(ListNode* head) {
        left=head;
        return tr(head);


    }
};
