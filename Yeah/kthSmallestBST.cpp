/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int findKth(TreeNode* root, int &k) {
    if (root == NULL) {
        return -1;
    }
    int ansLeft = findKth(root->left, k);
    if (!k) {
        return ansLeft;
    }
    k--;
    if (!k) {
        return root->val;
    } 
    return findKth(root->right, k);
}

int Solution::kthsmallest(TreeNode* root, int k) {
    return findKth(root, k);
}
