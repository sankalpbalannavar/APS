/* 
   Author: Sankalp Balannavar
   SRN: 01FE21BCS414
   Title: Add Two Numbers
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int carry = 0;
    while(l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node->val = sum % 10;
        new_node->next = NULL;
        carry = sum / 10;
        if(!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    return head;
}