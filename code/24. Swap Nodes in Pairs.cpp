//
// Created by bin gao on 2019-09-28.
//

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        for(auto p = dummy; p->next && p->next->next; ){
            auto a = p -> next, b = a -> next;
            p -> next = b;
            a -> next = b -> next;
            b -> next = a;
            p = a;
        }
        return dummy -> next;
    }
};