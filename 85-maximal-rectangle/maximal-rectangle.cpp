class Solution {
public:
//    vector<int>getNSR(vector<int>&ht){
//     int n = ht.size();
//     stack<int>st;
//     vector<int>nsr(n);
//     for(int i=n-1;i>=0;i--){
//         if(st.empty())
//         nsr[i] = n;
//         else{
//             while(!st.empty() && ht[st.top()]>=ht[i])st.pop();
//             if(st.empty())
//             nsr[i] = n;
//             else
//             nsr[i] = st.top();
//         }
//         st.push(ht[i]);
//     }
//     return nsr;
//    }
//     vector<int>getNSL(vector<int>&ht){
//     int n = ht.size();
//     stack<int>st;
//     vector<int>nsl(n);
//     for(int i=0;i<n;i++){
//         if(st.empty())
//         nsl[i] = -1;
//         else{
//             while(!st.empty() && ht[st.top()]>=ht[i])st.pop();
//             if(st.empty())
//             nsl[i] = -1;
//             else
//             nsl[i] = st.top();
//         }
//         st.push(ht[i]);
//     }
//     return nsl;
//    }
//    int findMaxArea(vector<int>& ht){
//     int n = ht.size();
//     vector<int>nsr = getNSR(ht);
//     vector<int>nsl = getNSL(ht);
//     int maxArea = 0;
//     for(int i=0;i<n;i++){
//         int a = ht[i]*(nsr[i]-nsl[i]-1);
//          maxArea = max(a,maxArea);
//     }
//     return maxArea;
//    }
//     int maximalRectangle(vector<vector<char>>& matrix) {
        
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int>ht(n);
//         for(int i=0;i<m;i++)
//         ht[i] = (matrix[0][i] == '0') ? 1 : 0;
//         int maxArea = findMaxArea(ht);
//         for(int r=1;r<m;r++){
//             for(int c=0;c<n;c++){
//                 if(matrix[r][c] == '0')
//                 ht[c] = 0;
//                 else
//                 ht[c] +=1;
//             }
//             maxArea = max(maxArea, findMaxArea(ht));
//         }
//         return maxArea;
//     }
 vector<int> NSR(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = n;
        vector<int> right(n);
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                right[i] = pseudo_index;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    right[i] = pseudo_index;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }
    vector<int> NSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = -1;
        vector<int> left(n);
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                left[i] = pseudo_index;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    left[i] = pseudo_index;
                else
                    left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }
    
    int MAH(vector<int>& heights) {
        int n = heights.size();
        vector<int> right = NSR(heights);
        vector<int> left  = NSL(heights);
        vector<int> width(n);
        for(int i = 0; i<n; i++)
            width[i] = right[i]-left[i]-1;
        int max_area = 0;
        
        for(int i = 0; i<n; i++) {
            int a =  width[i]*heights[i];
            if(max_area < a)
                max_area = a; 
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);
        for(int i = 0; i<m; i++) {
            height[i] = (matrix[0][i]=='1')?1:0;
        }
        int maxA = MAH(height);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            maxA = max(maxA, MAH(height));
        }
        return maxA;
    }
};