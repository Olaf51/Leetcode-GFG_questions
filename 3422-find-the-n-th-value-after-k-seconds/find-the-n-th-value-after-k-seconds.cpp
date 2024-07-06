class Solution {
public:
    int m = 1e9 + 7;
    int valueAfterKSeconds(int n, int k) {
       
        vector<int> x(n, 1);

        for(int i=0;i<k;i++){
            for(int j=1;j<n;j++)
            x[j] = (x[j]%m +  x[j-1]%m)%m;
        }

        return x[n - 1];
        
    }
};