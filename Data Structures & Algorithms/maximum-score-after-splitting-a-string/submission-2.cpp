class Solution {
public:
    int maxScore(string s) {
        int o = 0, z = 0;
        for(auto i:s){
            if(i=='1')
                o++;
        }
        int mx = 0;
        int k = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                k++;
                mx = max(mx,o+k);
            }
            else{
                o--;
                mx = max(mx,o+k);
            }
        }
        return mx;
    }
};