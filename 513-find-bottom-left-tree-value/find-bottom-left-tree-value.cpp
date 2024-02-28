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
//    int maxD = -1;
//    int res = 0;
//     void dfs(TreeNode* root, int curr){
//         if(!root)return;

//         if(curr > maxD){
//             maxD = curr;
//             res = root->val;
//         }
//         dfs(root->left,curr+1);
//         dfs(root->right, curr + 1);
//     }
    int findBottomLeftValue(TreeNode* root) {
        // dfs(root,0);
        // return res;
        int res=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
         TreeNode* temp = q.front();
         q.pop();
         res = temp->val;
         if(temp->right)q.push(temp->right);
         if(temp->left)q.push(temp->left);
        }
        return res;
        
    }
};