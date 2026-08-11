class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0,j=n-1;
        int ans = 0;
        while(i<j){
            int area = (j-i)*min(heights[i],heights[j]);
            ans = max(area,ans);
            if(heights[i]<heights[j])
                i++;
            else if(heights[i]>heights[j])
                j--;
            else{
                if(i+1<j-1 && heights[i+1]>heights[j-1]){
                    i++;
                }
                else if(i+1<j-1 && heights[i+1]<=heights[j-1])
                    j--;
                else
                    i++;
            }
        }
        return ans;
    }
};
