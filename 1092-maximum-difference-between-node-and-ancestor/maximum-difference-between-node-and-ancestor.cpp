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
//brute force
//int maxDiff ;
// void finddiff(TreeNode* root, TreeNode* child){
//     if(!root || !child)return ;
//     maxDiff = max(maxDiff, abs(root->val-child->val));
//     finddiff(root, child->left);
//     finddiff(root, child->right);
// }
// void temp(TreeNode* root){
//      if(!root) return ;
//         finddiff(root, root->left);
//         finddiff(root, root->right);

//         temp(root->left);
//         temp(root->right);
// }
//optimal
   int solve(TreeNode* root, int minv, int maxv){
       if(!root)
       return abs(maxv - minv);
       maxv = max(maxv, root->val);
       minv = min(minv, root->val);

       int left = solve(root->left,minv,maxv);
       int right = solve(root->right,minv,maxv);
       return max(left,right);
   }
    int maxAncestorDiff(TreeNode* root) {
       
     return solve(root,root->val,root->val);

    }
};