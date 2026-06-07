class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        // sort(nums.begin(),nums.end());
        int mn1 = INT_MAX, mn2 = INT_MAX;
        int mx1 = INT_MIN, mx2 = INT_MIN;
        for(auto i:nums){
            if(i<mn2)
            {
                mn2 = i;
                if(mn2<mn1){
                    swap(mn1,mn2);
                }
            }
            if(i>mx2)
            {
                mx2 = i;
                if(mx2>mx1){
                    swap(mx1,mx2);
                }
            }
        }
        
        return abs(mn1*mn2 - mx1*mx2);
    }
};