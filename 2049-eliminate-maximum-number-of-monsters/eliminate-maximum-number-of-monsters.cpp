class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int>time(dist.size());
        for(int i =0;i<dist.size();i++){
            time[i] = ceil((float)dist[i]/speed[i]);
        }
        sort(begin(time), end(time));
        int cnt = 1,tim_passed = 1;
        for(int i=1;i<time.size();i++){
            if(time[i]-tim_passed <=0)return cnt;
            cnt++;
            tim_passed++;
        }
        return cnt;

        
    }
};