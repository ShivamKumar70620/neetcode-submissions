class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 1, ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ans)    
                c++;
            else
                c--;
            if(c<0){
                c = 0;
                ans = nums[i];
            }
        }
        return ans;
    }
};