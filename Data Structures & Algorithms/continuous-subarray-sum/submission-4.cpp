class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int cs = 0;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            cs += nums[i];
            int r = cs % k;
            if(mp.find(r) == mp.end())
                mp[r] = i;
            else{ 
                if(i - mp[r] > 1)
                    return true;
            }
            
        }
        return false;
    }
};