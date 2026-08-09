class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        int res = 0;
        for(auto i:nums){
            if(!mp[i]){
                mp[i] = mp[i-1] + mp[i+1] + 1;
                mp[i - mp[i-1]] = mp[i];
                mp[i + mp[i+1]] = mp[i];
                res = max(res, mp[i]);
            }
        }
        return res;
    }
};
