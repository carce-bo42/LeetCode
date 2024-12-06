/* https://leetcode.com/problems/minimum-depth-of-binary-tree/description/ */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int minDepth(struct TreeNode* root){
    if (!root) {
        return 0;
    } else {
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if ((left==0) ^ (right==0))
            return (left>right?left:right)+1;
        if(left > right)
            return right + 1;
        else
            return left + 1;
    }
}