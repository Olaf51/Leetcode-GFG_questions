class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
        int maxf =0, numf =0;
        for(auto i: tasks)
            v[i-'A']++;
            
        for(int i=0;i<26;i++){
            if(v[i] == maxf)numf++;
            if(maxf<v[i]){
                maxf = v[i];
                numf = 1;
            }
        }
        int gap = n-(numf-1);
        int tgap = (maxf-1)*gap;
        int rem = tasks.size()-numf*maxf;
        int idle = 0;
        idle =  max(0, tgap-rem);
        return idle + tasks.size();
        
    }
};