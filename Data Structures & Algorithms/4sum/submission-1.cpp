class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long val1 = nums[i]+nums[j];
                int k = j+1, l = n-1;
                while(k<l){
                    long val2 = nums[k]+nums[l];
                    if(val1+val2==target){
                ans.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                    }
                    else if(val1+val2<target) k++;
                    else l--;
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};