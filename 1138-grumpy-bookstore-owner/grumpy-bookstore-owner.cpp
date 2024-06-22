class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int curr =0;
        int perm = 0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0)
            perm += customers[i];
            else if(i<minutes)
                curr += customers[i];
            
        }
        int x = curr;
        for(int i=minutes;i<customers.size();i++){
            curr += customers[i]*grumpy[i];
            curr -= customers[i-minutes]*grumpy[i-minutes];
            x = max(x, curr);
        }
        return x + perm;
    }
};