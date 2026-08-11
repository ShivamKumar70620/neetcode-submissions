class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)
            return 0;
        int i = 1, j = n-2;
        int mxl = height[0], mxr = height[n-1];
        int ans = 0;
        while(i<=j){
            // cout<<i<<" "<<j<<" "<<ans<<endl;
            if(i==j){
                int val = min(mxl-height[i],mxr-height[i]);
                if((height[i]<mxl || height[i]<mxr) && val>0)
                    ans += val;
                break;
            }
            if(mxl<mxr){
                if(height[i]<mxl){
                    ans += (mxl-height[i]);
                }
                else{
                    mxl = height[i];
                }
                i++;
            }
            else {
                if(height[j]<mxr){
                    ans += (mxr-height[j]);
                }
                else{
                    mxr = height[j];
                }
                j--;
            }
        }
        return ans;
    }
    
};
