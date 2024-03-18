class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
            sort(points.begin(), points.end(), [](const vector<int> &v1,const  vector<int> &v2) {return v1[1] < v2[1];} );
        int x = points[0][1];
        int ct = 1,n = points.size();
        for(int j=0;j<n;j++){
            if(x >= points[j][0] && x <= points[j][1]) continue;
        else {
            ct++;
            x = points[j][1];
        }
           
        }
        return ct;
        
    }
};