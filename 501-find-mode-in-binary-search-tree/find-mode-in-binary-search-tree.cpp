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
   void inorder(TreeNode* root, vector<int>&res){
       if(root == NULL)return ;
       res.push_back(root->val);
       inorder(root->left,res);
       inorder(root->right,res);
   }
    vector<int> findMode(TreeNode* root) {
        vector<int>res, ans;
        inorder(root,res);
        int maxx = INT_MIN;
        unordered_map<int,int>mp;

        for(auto i: res){
            mp[i]++;
            maxx = max(maxx,mp[i]);
        }
        for(auto i: mp){
            if(i.second == maxx)
            ans.push_back(i.first);
        }
        return ans;
        
    }
};