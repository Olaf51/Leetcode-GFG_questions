class Solution {
public:
    int pivotInteger(int n) {
        int tsum = n*(n+1)/2;
        for(int p=1;p<=n;p++){
            int l = p*(p+1)/2;
            int r = tsum - l + p;
            if(l==r)
            return p;
        }
        return -1;
        
    }
};