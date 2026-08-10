class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i<j){
            // cout<<nums[i]+nums[j]<<endl;
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else
                return {i+1,j+1};
        }
        return {};
    }
};
