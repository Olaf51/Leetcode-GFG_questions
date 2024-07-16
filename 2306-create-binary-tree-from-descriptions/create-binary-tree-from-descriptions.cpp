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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>mp;
        unordered_set<int>st;
        for(auto &it: descriptions){
             int papa = it[0];
             int child = it[1];
             int l = it[2];
             if(mp.find(papa) == mp.end())
             mp[papa] = new TreeNode(papa);
             if(mp.find(child) == mp.end())
             mp[child] = new TreeNode(child);
             if(l)mp[papa]->left = mp[child];
             else mp[papa]->right = mp[child];
             st.insert(child);
        }

         for(auto &it: descriptions){
            if(st.find(it[0]) == st.end())return mp[it[0]];
         }
         return nullptr;


        
    }
};