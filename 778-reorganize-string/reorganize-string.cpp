class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        vector<int>v(26,0);
        int n = s.size();
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
            if(v[s[i]-'a']>(n+1)/2)
            return "";
        }
        for(int i=0;i<26;i++){
            if(v[i]>0){
                pq.push({v[i],(char)i + 'a'});
            }
        }
        string ans = "";
        while(pq.size()>=2){
            pair<int,char>p1 = pq.top();
            pq.pop();
            pair<int,char>p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            if(p1.first>1){
                pq.push({p1.first-1,p1.second});
            }
               if(p2.first>1){
                pq.push({p2.first-1,p2.second});
            }

        }
        if(pq.size()==1)
        ans += pq.top().second;
        return ans;

        
    }
};