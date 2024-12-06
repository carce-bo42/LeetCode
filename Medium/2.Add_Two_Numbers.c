/* https://leetcode.com/problems/add-two-numbers/description/ */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

void sum_numbers(struct ListNode* res, struct ListNode* prev, struct ListNode* l1, struct ListNode* l2, int leftover) {
    if (l1 == 0 && l2 == 0) {
        if (leftover == 0) {
            prev->next = 0;
            free(res);
            return ;
        } else {
            res->val = leftover;
            return ;
        }
    }
    res->next = malloc(sizeof(struct ListNode));
    res->next->next = 0;
    if (l1 == 0) {
        res->val = (l2->val + leftover) % 10;
        return sum_numbers(res->next, res, l1, l2->next, (l2->val + leftover)/10);
    } else if (l2 == 0) {
        res->val = (l1->val + leftover) % 10;
        return sum_numbers(res->next, res, l1->next, l2, (l1->val + leftover)/10);
    } else {
        res->val = (l1->val + l2->val + leftover) % 10;
        return sum_numbers(res->next, res, l1->next, l2->next, (l1->val + l2->val + leftover)/10);
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* n = malloc(sizeof(struct ListNode));
    n->val = 0;
    n->next = 0;
    sum_numbers(n, 0, l1, l2, 0);
    return n;
}