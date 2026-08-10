class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int curSum = 0, ans = 0;
        int n = nums.size();
        mp[0] = 1;
        for(int i=0;i<n;i++){
            curSum += nums[i];
            int diff = curSum - k;
            ans += mp[diff];
            mp[curSum] ++;
        }
    
        return ans;
    }
};