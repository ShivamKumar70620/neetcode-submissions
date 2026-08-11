class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j = i+1, k = n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    v.insert({nums[i],nums[j],nums[k]});
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        vector<vector<int>> ans(v.begin(),v.end());
        return ans;
    }
};
