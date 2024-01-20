// class Solution {
//     vector<int>LSL(vector<int>&arr, int n){
//         vector<int>res(n);
//         stack<int>st;
//         for(int i=0;i<n;i++){
//             if(st.empty())
//             res[i] = -1;
//             else{
//                 while(!st.empty() && arr[st.top()]>=arr[i])
//                 st.pop();
//                 res[i] = st.empty()?-1:st.top();
//             }
//             st.push(i);
//         }
//         return res;
//     }
//     vector<int>LSR(vector<int>&arr, int n){
//         vector<int>res(n);
//         stack<int>st;
//         for(int i=n-1;i>=0;i--){
//             if(st.empty())
//             res[i] = n;
//             else{
//                 while(!st.empty() && arr[st.top()]>arr[i])
//                 st.pop();
//                 res[i] = st.empty()?n:st.top();
//             }
//             st.push(i);
//         }
//         return res;
//     }
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         vector<int>lsl = LSL(arr,n);
//         vector<int>lsr = LSR(arr,n);
//         long long sum = 0;
//         int mod = 1e9 + 7;
//         for(int i=0;i<n;i++){
//             int li =lsl[i];
//             int ri = lsr[i];
//             int prod = li*ri*arr[i];
//             sum = (sum + prod)%mod;
//         }
//         return sum;
        
//     }
// };
using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        ll sum = 0;

        for (int i = 0; i < length; ++i) {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};