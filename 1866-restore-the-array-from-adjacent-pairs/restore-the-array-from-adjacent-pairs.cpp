// class Solution {
// public:
//   vector<int>res;
//   void dfs(int start, int prev,  unordered_map<int, vector<int>>&vec){
//       res.push_back(start);
//       for(auto &i: vec[start]){
//           if(i!= prev)
//           dfs(i,start,vec);
//       }
//   }
//     vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
//         unordered_map<int, vector<int>>vec;
//         for(vector<int> &i: adjacentPairs){
//             int u = i[0];
//             int v = i[1];
//             vec[u].push_back(v);
//             vec[v].push_back(u);
//         }
//         int start = -1;
//         for(auto &i: vec){
//             if(i.second.size() == 1)
//             start = i.first;
//             break; 
//         }
//         dfs(start,INT_MIN,vec);
//         return res;
        
//     }
// };
class Solution {
public:
    std::vector<int> restoreArray(std::vector<std::vector<int>>& vals) {
        std::unordered_map<int, std::vector<int>> pairs;
        
        for (const std::vector<int>& val : vals) {
            pairs[val[0]].push_back(val[1]);
            pairs[val[1]].push_back(val[0]);
        }
        
        std::vector<int> result;
        int start = -1000000;
        
        for (const auto& entry : pairs) {
            if (entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }
        
        int left = -1000000;
        result.push_back(start);
        
        for (int i = 1; i < vals.size() + 1; ++i) {
            const std::vector<int>& val = pairs[start];
            int newval = (val[0] == left) ? val[1] : val[0];
            result.push_back(newval);
            left = start;
            start = newval;
        }
        
        return result;
    }
};