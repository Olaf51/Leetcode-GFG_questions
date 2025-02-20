// class Solution {
// public:
//      int myAtoi(string s) {
    //    int n=s.size();
    //    if(n==0) return 0;
    //    int i=0;
    //    while(i<n && s[i]==' ')
    //    {
    //     i++;
    //    }
    //    s=s.substr(i);
    //    int sign=1;
    //    long long ans=0;
    //    n=s.size();
    //    if(s[0]=='-') sign=-1;
    //    int MAX= INT_MAX;
    //    int MIN= INT_MIN;
    //    i= (s[0]=='-' || s[0]=='+')? 1:0;
    //    while(i<n)
    //    {
    //     if(s[0]==' ' || !isdigit(s[i])) break;
    //     ans=ans*10+(s[i]-'0');
    //     i++;
    //    }
    //     if(sign==-1 && ans<MIN) return MIN;
    //     if(sign==1 && ans>MAX) return MAX;
    //    return (int)(sign*ans);
    class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;  // Trim leading spaces

        if (i == n) return 0;  // If string is empty after spaces

        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {  // Handle sign
            if (s[i] == '-') sign = -1;
            i++;
        }

        long long ans = 0;
        int MAX = INT_MAX, MIN = INT_MIN;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // **Check overflow before adding the digit**
            if (ans > (MAX - digit) / 10) {
                return (sign == 1) ? MAX : MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};


