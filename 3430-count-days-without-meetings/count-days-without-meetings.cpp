class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings),end(meetings));
        int last = meetings[0][1];
        int cnt=0;
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]>last){
                cnt += meetings[i][0] - last-1;
            }
            last = max(last,meetings[i][1]);
        }
        cnt += meetings[0][0]-1;
        if(days> last)cnt += days-last;
        return cnt;
        
    }
};