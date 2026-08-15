class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum<target) return 0;
        int n = nums.size();
        int i=0,j=0;
        int ans = INT_MAX;
        sum = 0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                ans = min(ans, j-i+1);
                sum -= nums[i++];
            }
            j++;

        }
        return ans==INT_MAX?0:ans;
    }
};