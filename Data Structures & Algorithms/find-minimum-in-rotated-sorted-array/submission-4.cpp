class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int ans = nums[0];
        if(r==0) return ans;
        while(l<=r){
            int mid = l + (r-l)/2;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            if(nums[mid]<=nums[mid+1]){
                if(nums[l]>=nums[mid]){
                    r = mid;
                }
                else{
                    if(nums[mid]>=nums[r]){
                        l = mid;
                    }
                    else
                        r = mid;
                }
            }
            else{
                ans = min(ans,nums[mid+1]);
                break;
            }
            if(l==r)
                break;
        }
        return ans;
    }
};
