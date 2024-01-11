/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int maxDiff ;
void finddiff(TreeNode* root, TreeNode* child){
    if(!root || !child)return ;
    maxDiff = max(maxDiff, abs(root->val-child->val));
    finddiff(root, child->left);
    finddiff(root, child->right);
}
void temp(TreeNode* root){
     if(!root) return ;
        finddiff(root, root->left);
        finddiff(root, root->right);

        temp(root->left);
        temp(root->right);
}
    int maxAncestorDiff(TreeNode* root) {
       maxDiff = -1;
       temp(root);
        return maxDiff;

    }
};