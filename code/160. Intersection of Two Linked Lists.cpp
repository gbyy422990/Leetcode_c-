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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //解法一
        auto a = headA, b = headB;
        int lenA = 0, lenB = 0;

        if(headA == NULL || headB == NULL) return NULL;

        for(auto p = a; p != NULL; p = p->next) lenA++;
        for(auto p = b; p != NULL; p = p->next) lenB++;

        if(lenA > lenB){
            for(int i = 0; i < lenA - lenB; i++){
                a = a -> next;
            }
        }
        if(lenA < lenB){
            for(int i = 0; i < lenB - lenA; i++){
                b = b -> next;
            }
        }

        if(a == b) return a;
        while(a != NULL){
            a = a -> next;
            b = b -> next;
            if(a == b){
                return a;
            }
        }
        return NULL;

        //解法二
        /*
         auto a = headA, b = headB;
        while(a != b){
            if(a != NULL) a = a -> next;
            else a = headB;

            if(b != NULL) b = b -> next;
            else b = headA;
        }
        return a;
         */
    }
};