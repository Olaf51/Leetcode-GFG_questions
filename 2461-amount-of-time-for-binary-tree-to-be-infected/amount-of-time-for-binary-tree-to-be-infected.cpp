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
 void makeGraph( unordered_map<int,vector<int>>&adj, TreeNode* curr, int papa){
     if(curr == NULL)return ;
     if(papa != -1)
     adj[curr->val].push_back(papa);
     if(curr->left)
     adj[curr->val].push_back(curr->left->val);
      if(curr->right)
     adj[curr->val].push_back(curr->right->val);
     makeGraph(adj,curr->left,curr->val);
     makeGraph(adj,curr->right,curr->val);

 }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        makeGraph(adj,root,-1);

        unordered_set<int>vis;
        queue<int>q;
        int min=0;
        q.push(start);
        vis.insert(start);
        while(!q.empty()){
              int n = q.size();
              while(n--){
                  int temp = q.front();
                  q.pop();
                  for(auto &it : adj[temp]){
                      if(vis.find(it) == vis.end()){
                          q.push(it);
                          vis.insert(it);
                      }
                  }
                  
              }
              min++;

        }
        return min-1;
        
    }
};