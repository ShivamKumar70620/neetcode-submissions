class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int cMin = 1, cMax = 1;
        for(auto i:nums){
            int tmp = cMax*i;
            cMax = max(max(cMax*i, cMin*i), i);
            cMin = min(min(cMin*i, tmp), i);
            ans = max(cMax, ans);
        }
        return ans;
    }
};
