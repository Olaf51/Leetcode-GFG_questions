class Solution {
public:
int t[101][101];
int solve(vector<vector<int>>& matrix,int r, int c,int n){
    if(r == n-1)
    return matrix[r][c];
    if(t[r][c]!= INT_MAX)return t[r][c];
    int sum = matrix[r][c];
    int minSum = INT_MAX;
    if(r+1<n && c-1>=0)
    minSum = min(minSum, sum + solve(matrix,r+1,c-1,n));
    if(r+1<n)
    minSum = min(minSum, sum + solve(matrix,r+1,c,n));
    if(r+1<n && c+1<n)
    minSum = min(minSum, sum + solve(matrix,r+1,c+1,n));
    return t[r][c] = minSum;


}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //memset(t,-1,sizeof(t));
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++)
            t[i][j] = INT_MAX;
        }
        int n = matrix.size();
        int res = INT_MAX;
        int r=0;
        for(int i=0;i<n;i++)
        res = min(res, solve(matrix,r,i,n));
        return res;

        
    }
};