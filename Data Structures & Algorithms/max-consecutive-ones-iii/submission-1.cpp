class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0,ans=0,zcount=0;
        while(j<n){
            if(nums[j]==0) zcount++;
            if(zcount<=k)
                ans = max(ans,j-i+1);
            else{
                if(nums[i]==0)
                    zcount--;
                i++;
            }
            j++;
        }
        return ans;
    }
};