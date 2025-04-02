class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long Trip = 0, Ele = 0, Diff = 0;
        for (long n : nums) {
            Trip = max(Trip, Diff * n);
            Diff = max(Diff, Ele - n);
            Ele = max(Ele, n);
        }
        return Trip;
        
    }
};