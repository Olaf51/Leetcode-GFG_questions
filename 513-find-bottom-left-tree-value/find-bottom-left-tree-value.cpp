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
   int maxD = -1;
   int res = 0;
    void dfs(TreeNode* root, int curr){
        if(!root)return;

        if(curr > maxD){
            maxD = curr;
            res = root->val;
        }
        dfs(root->left,curr+1);
        dfs(root->right, curr + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return res;
        
    }
};