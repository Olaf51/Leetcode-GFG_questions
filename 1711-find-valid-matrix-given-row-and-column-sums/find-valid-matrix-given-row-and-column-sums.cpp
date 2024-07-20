class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int x = rowSum.size();
        int y = colSum.size();
        vector<vector<int>>v(x, vector<int>(y,0));
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(rowSum[i]<colSum[j]){
                    v[i][j] = rowSum[i];
                    colSum[j] -= rowSum[i];
                    rowSum[i] = 0;
                }
                else{
                    v[i][j] = colSum[j];
                    rowSum[i] -= colSum[j];
                    colSum[j] = 0; 
                }
            }
        }
        return v;

        
    }
};