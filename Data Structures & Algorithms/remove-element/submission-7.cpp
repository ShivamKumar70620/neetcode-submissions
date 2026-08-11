class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==1){
            if(nums[0]==val) return 0;
            else return 1;
        } 
        int i = 0, j = n-1, c = 0;
        while(i<j){
            while(j>=0 && nums[j]==val){ c++,j--;}
            if(j<0) break;
            // cout<<i<<" "<<j<<endl;
            if(nums[i]==val){
                c++;
                swap(nums[i],nums[j]);
                i++;
                j--;
                if(i==j && nums[i]==val) {c++; break;}
            }
            else{
                i++;
            }
        }
        cout<<c<<endl;
        return n-c;
    }
};