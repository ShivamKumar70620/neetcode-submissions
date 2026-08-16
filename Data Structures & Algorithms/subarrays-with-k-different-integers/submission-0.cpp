class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fn(nums,k) - fn(nums,k-1);
    }
    int fn(vector<int>& nums, int k){
        int n = nums.size();
        if(n<k) return 0;
        unordered_map<int,int> mp;
        int ans = 0;
        int j = 0, i = 0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            ans += (j-i+1);
            j++;

        }
        return ans;
    }
};