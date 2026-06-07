class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = -1;
        int ans = 0;
        int s = -1;
        for(auto i:prices){
            if(b==-1){
                b = i;
            }
            if(i>b){
                if(s==-1 || i>=s){
                    s = i;
                }
                else{
                    ans+= s-b;
                    b = i;
                    s = -1;
                }
            }
            else{
                if(s!=-1){
                    ans+= s-b;
                    s = -1;
                }
                b = i;
            }
        }
        if(s!=-1)
            ans += s - b;
        return ans;
    }
};