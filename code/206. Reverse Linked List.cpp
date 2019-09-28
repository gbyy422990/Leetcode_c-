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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        auto a = head, b = head -> next;
        while(b){
            auto c = b -> next;
            b -> next = a;
            a = b, b = c;
        }
        head -> next = NULL;
        head = a;
        return head;
    }
};