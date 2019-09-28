//
// Created by bin gao on 2019-09-28.
//

/**
- Definition for singly-linked list.
- struct ListNode {
- int val;
- ListNode *next;
- ListNode(int x) : val(x), next(NULL) {}
- };
  */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //创建一个虚拟头节点，可以避免处理删除头节点的问题
        //1、建立虚拟头节点；
        auto dummy = new ListNode(-1);
        dummy -> next = head;
        auto first = dummy, second = dummy;

        //2、first指针向后走n步；
        while(n--){
            first = first -> next;
        }

        //3、fisrt和second指针同时向后走，直到first指针到链表尾；
        while(first -> next){
            first = first -> next;
            second = second -> next;
        }

        //4、删除节点；
        second -> next = second -> next -> next;
        return dummy -> next;
    }
};