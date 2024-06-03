class Solution {
public:
    int characterReplacement(string s, int k) {
        int mfreq=0,r=0,l=0,mlen=0;
        int n = s.size();
        int hash[26] = {0};
        while(r<n){
            hash[s[r]-'A']++;
            mfreq = max(mfreq,hash[s[r]-'A']);
            if(r-l+1 - mfreq > k){
                hash[s[l]-'A']--;
                l++;
            }
            if(r-l+1-mfreq <= k)
            mlen = max(mlen,r-l+1);
            r++;

        }
        return mlen;
        
    }
};