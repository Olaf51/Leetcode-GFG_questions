class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m = left,n = right;
        int cnt = 0;
        while(m!=n){
            m>>=1;
            n>>=1;
            cnt++;
        }
        return m<<=cnt;
        
    }
};