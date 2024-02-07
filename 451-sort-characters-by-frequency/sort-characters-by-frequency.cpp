class Solution {
public:
    string frequencySort(string s) {
       map<char,int>mp;
       for(auto i:s)
       mp[i]++;
       priority_queue<pair<int,char>> pq;
       for(auto i: mp)
       pq.push({i.second,i.first});
       string ss = "";
       while(!pq.empty()){
          int k = pq.top().first;
          while(k>0){
          ss += pq.top().second;
          k--;
          }
          pq.pop();
       }

       return ss;
       
        
    }
};