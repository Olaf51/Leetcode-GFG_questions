class Solution {
public:
    bool halvesAreAlike(string s) {
        auto countVowel = [](const string &str){
            unordered_set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            int cnt = 0;
            for(auto it: str){
                if(st.count(it)>0)
                cnt++;
            }
            return  cnt;
        };
        int n = s.size();
        int mid = n/2;
        string s1 = s.substr(0,n/2);
        string s2 = s.substr(n/2);
        return countVowel(s1) == countVowel(s2);
        
    }
};