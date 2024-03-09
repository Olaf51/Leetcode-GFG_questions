class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i=0,j=n-1;
        sort(begin(tokens),end(tokens));
        int maxtoken = 0, s=0;
        while(i<=j){
        if(power >= tokens[i]){
             power -= tokens[i];
             s += 1;
             maxtoken = max(maxtoken,s);
             i++;
        }
        else if(s >= 1){
            s-= 1;
            power += tokens[j];
            j--;
        }
        else
        return maxtoken;
    }
    return maxtoken;
    }
};