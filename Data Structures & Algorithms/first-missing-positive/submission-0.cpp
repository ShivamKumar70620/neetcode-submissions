class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minNum = INT_MAX, maxNum = -1;
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<=0 || nums[i]>n){
                i++;
                continue;
            }
            else {
                int ind = nums[i]-1;
                if(nums[i]!=nums[ind]){
                    swap(nums[ind], nums[i]);
                }
                else   
                    i++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)
                return i+1;
            
        }
        return n + 1;
    }
};