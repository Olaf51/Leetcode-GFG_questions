class Solution {
public:
int t[501];
int n;
int solve(int i,vector<int>&arr, int k){
    if(i>=n)return 0;
    if(t[i]!=-1)return t[i];
   int res = -1;
    int curr_max=-1;
    for(int j=i;j<n && (j-i+1)<=k;j++){
        curr_max = max(curr_max,arr[j]);
        res = max(res,(((j-i+1)*curr_max) + solve(j+1,arr,k)));
    }
    return t[i] = res;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(t,-1,sizeof(t));
        n = arr.size();
        return solve(0,arr,k);

        
    }
};