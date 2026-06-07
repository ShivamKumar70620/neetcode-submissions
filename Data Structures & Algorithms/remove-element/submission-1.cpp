class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            // cout<<i<<" "<<j<<endl;
            while(j>=0 && nums[j]==val)
                j--;
            if(j<0)
                break;
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
            }
            i++;
        }

        return j+1;
    }
};