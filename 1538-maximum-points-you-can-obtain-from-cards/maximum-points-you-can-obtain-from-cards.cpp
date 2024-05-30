class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum =0;
       for(int i=0;i<k;i++)sum+=cardPoints[i];
       int l=0,r=cardPoints.size()-1;
       int mx = sum;
       int t = k-1;
       while(t>=0){
          sum -= cardPoints[t];
          sum += cardPoints[r];
          mx = max(mx,sum);
          t--;
          r--;
       }
       return mx;
    }
};