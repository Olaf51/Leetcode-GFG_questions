// class Solution {
// public:
//    int mod = 1e9 + 7;
//     int numFactoredBinaryTrees(vector<int>& arr) {
//         int n = arr.size();
//         sort(begin(arr),end(arr));
//         unordered_map<int,long long>mp;
//         for(auto i: arr)
//          mp[i] = 1;
//          for(int i=1;i<n;i++){
//              int root = arr[i];
//              for(int j=0;j<i;j++){
//                 if(root%arr[j]==0 && mp.find(root/arr[j])!= mp.end())
//                   mp[root] += (mp[root/arr[j]]%mod*mp[arr[j]]%mod)%mod;
//              }
//          }
//          int res = 0;
//          for(auto it: mp)
//          res = res + (it.second)%mod;
//         return res;
//     }
// };
const int MOD = 1e9 + 7;

class Solution {
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::unordered_set<int> s(arr.begin(), arr.end());
        std::unordered_map<int, int> dp;
        for (int x : arr) dp[x] = 1;
        
        for (int i : arr) {
            for (int j : arr) {
                if (j > std::sqrt(i)) break;
                if (i % j == 0 && s.find(i / j) != s.end()) {
                    long long temp = (long long)dp[j] * dp[i / j];
                    if (i / j == j) {
                        dp[i] = (dp[i] + temp) % MOD;
                    } else {
                        dp[i] = (dp[i] + temp * 2) % MOD;
                    }
                }
            }
        }
        
        int result = 0;
        for (auto& [_, val] : dp) {
            result = (result + val) % MOD;
        }
        return result;
    }
};