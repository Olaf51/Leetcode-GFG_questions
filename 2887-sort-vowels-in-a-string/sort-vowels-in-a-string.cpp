class Solution {
public:
    string sortVowels(string s) {
         
        auto isVowel = [](char c) {
            c = tolower(c);
            return c == 'a' ||  c == 'e' || c == 'i'||  c == 'o' || c == 'u';
        };

        string vow, cons;
        for (char t : s) {
            if (isVowel(t))
                vow += t;
            else
                cons += t;
        }

        sort(vow.begin(), vow.end());

        string ans;
        int vowInd = 0, conInd = 0;
        for (char t : s) {
            if (isVowel(t))
                ans += vow[vowInd++];
            else
                ans += cons[conInd++];
        }

        return ans;
    }
};