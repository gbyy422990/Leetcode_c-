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
    ListNode* deleteDuplicates(ListNode* head) {
        auto curr = head;
        while(curr){
            if(curr -> next && curr -> val == curr -> next -> val) curr -> next = curr -> next -> next;
            else curr = curr -> next;
        }
        return head;
    }
};