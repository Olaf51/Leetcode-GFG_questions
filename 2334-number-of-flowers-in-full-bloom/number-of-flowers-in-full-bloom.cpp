class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int,int>>vec;
        for(int i=0;i<people.size();i++){
            vec.push_back({people[i],i});
        }
        sort(vec.begin(),vec.end());
        sort(flowers.begin(),flowers.end());
        int l=0;
        multiset<int>s;
        vector<int>ans(people.size());
        for(int i=0;i<vec.size();i++){
              while(l<flowers.size() && vec[i].first>=flowers[l][0])
                s.insert(flowers[l][1]), l++;
              while(s.size() && (*(s.begin()) < vec[i].first))
                s.erase(s.begin());
                ans[vec[i].second] = s.size();
        }
        return ans;
        
    }
};