class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,k=0,j=nums.size()-1;
        while(i<=j){
           if(nums[k]==0){
            while(k<=nums.size() && nums[k]==0)
                k++;
            i = k;
           }
            while(j>=0 && nums[j]==2)
                j--;
            if(j<0 || k>=nums.size())
                break;
            if(nums[i]==0){
                swap(nums[i],nums[k]);
            }
            else if(nums[i]==2)
                swap(nums[i],nums[j]);
            else
                i++;
        }
    }
};