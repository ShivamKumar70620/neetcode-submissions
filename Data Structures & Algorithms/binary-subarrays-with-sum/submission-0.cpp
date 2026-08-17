class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0) return fn(nums,goal);
        return fn(nums,goal) - fn(nums,goal-1);
    }
    int fn(vector<int> nums, int goal){
        int n = nums.size();
        int i=0,j=0,zcount=0,ans=0,sum=0;
        while(j<n){
            cout<<sum<<endl;
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            if(sum<=goal)
                ans+=(j-i+1);
            j++;
        }
        cout<<ans<<endl;
        return ans;
    }
};