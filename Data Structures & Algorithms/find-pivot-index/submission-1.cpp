class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            nums[i] = sum;
        }
        int temp = 0;
        for(int i=0;i<n-1;i++){
            if(i==0 && nums[n-1] - nums[0] == 0){
                return 0;
            }
            else if(i==n-1 && nums[n-2] - nums[0]==0)
                return n-1;
            cout<<nums[i]<<" "<<nums[n-1]-nums[i+1]<<endl;
            if(nums[i]==(nums[n-1]-nums[i+1]))
                return i+1;
        }
        return -1;
    }
};