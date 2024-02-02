class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>qt;
        for(int i=1;i<=9;i++)
        qt.push(i);
        vector<int> res;
        while(qt.size()){
            int temp = qt.front();
            qt.pop();
            if(temp>high)
            continue;
            if(temp>=low && temp <= high)
            res.push_back(temp);
            int rem = temp%10;
            if(rem<9){
                qt.push(temp*10 + (rem + 1));
            }
        }
        return res;

        
    }
};