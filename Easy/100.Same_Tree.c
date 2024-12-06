/* https://leetcode.com/problems/same-tree/description/ */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <stdbool.h>

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    /* must be accessible */
    if (!p && !q) {
        return true;
    }
    /* one of them does not exist */
    if (!p || !q) {
        return false;
    }
    if (p->val == q->val) {
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
    return false;
}