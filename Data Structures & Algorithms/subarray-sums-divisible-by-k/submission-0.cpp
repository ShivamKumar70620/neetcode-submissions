class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int cs = 0,sum=0;
        for(auto i:nums){
            cs+=i;
            int rem = cs % k;
            if(cs%k==0)
                sum ++;
            if(mp.find(rem)!=mp.end()){
                sum+= mp[rem];
            }
            
            mp[rem]++;
        }
        return sum;
    }
};