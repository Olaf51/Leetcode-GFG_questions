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
int ans = 0;
   int solve(TreeNode* root, int st){
        if(!root){
            return 0;
        }
        st = st*10 + root->val;
        if(!root->left && !root->right)
        return st;
        int left = solve(root->left,st);
        int right = solve(root->right,st);
        return left + right;
   }
    int sumNumbers(TreeNode* root) {
       return  solve(root, 0);
      
        
    }
};