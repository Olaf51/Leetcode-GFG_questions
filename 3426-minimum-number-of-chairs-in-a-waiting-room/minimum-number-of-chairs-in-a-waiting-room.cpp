class Solution {
public:
    int minimumChairs(string s) {
        int ch = 0,temp=0;
        for(auto &it : s){
            if( it == 'E'){
                temp++;
                ch = max(ch,temp);
            }
            else
            temp--;
        }
        return ch;
        
    }
};