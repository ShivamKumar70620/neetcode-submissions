class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int i=0,j=n-1,k=n-1;
        while(i<=j){
            if(nums[i]*nums[i]>=nums[j]*nums[j]){
                // cout<<'1'<<endl;
                v[k--] = nums[i]*nums[i];
                i++;
            }
            else{
                // cout<<'2'<<endl;
                v[k--] = nums[j]*nums[j];
                j--;
            }
            
        }
        return v;
    }
};