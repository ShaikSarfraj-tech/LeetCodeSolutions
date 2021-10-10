class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int bits = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            bits |= nums[i];
        }
        return bits*pow(2, n-1);
    }
};