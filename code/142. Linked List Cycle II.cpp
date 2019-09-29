//
// Created by bin gao on 2019-09-29.
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
    ListNode *detectCycle(ListNode *head) {
        auto fast = head, slow = head;
        while(fast && slow){
            slow = slow -> next;
            fast = fast -> next;
            if(fast != NULL) fast = fast -> next;
            else return NULL;

            if(fast == slow){
                slow = head;
                while(fast != slow){
                    fast = fast -> next;
                    slow = slow -> next;
                }
                return fast;
            }
        }
        return NULL;
    }
};