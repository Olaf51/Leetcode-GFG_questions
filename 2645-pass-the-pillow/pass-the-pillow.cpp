class Solution {
public:
    int passThePillow(int n, int time) {
    n--;
    int temp = time/n;
    int rem = time%n;
    if(temp & 1)return n-rem+1;
    return rem+1;

        
    }
};