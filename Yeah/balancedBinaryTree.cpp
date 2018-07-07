/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int getDepth(TreeNode* root, bool &balanced) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = getDepth(root->left, balanced);
    int rightDepth = getDepth(root->right, balanced);
    if (abs(leftDepth - rightDepth) > 1) {
        balanced = false;
    }
    return max(leftDepth, rightDepth) + 1;
}

int Solution::isBalanced(TreeNode* root) {
    bool balanced = true;
    getDepth(root, balanced);
    return balanced;
}
