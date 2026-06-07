class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size();
        while(i<j){
            // cout<<i<<" "<<j<<endl;
           
            if(nums[i]==val){
                swap(nums[i],nums[--j]);
            }
            else
                i++;
        }

        return j;
    }
};