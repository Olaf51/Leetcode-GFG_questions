class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>res(n,0);
        sort(deck.begin(),deck.end());
        bool skip = false;
        int i=0,j=0;
        while(i<n){
            if(res[j] == 0){
               if(skip == false){
                res[j] = deck[i];
                i++;
               }
               skip = !skip;
            }
            j = (j+1)%n;
        }
        return res;
        
    }
};