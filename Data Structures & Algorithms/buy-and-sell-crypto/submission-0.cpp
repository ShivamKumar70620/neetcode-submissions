class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        int k = -1;
        for(auto i: prices){
            if(k==-1){
                k = i;
            }
            else if(k > i)
                k = i;
            else{
                p = max(p, i - k);
            }
        }
        return p;
    }
};
